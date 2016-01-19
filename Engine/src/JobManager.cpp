#include "JobManager.h"
#include "Thread.h"
#include "EngineInternals.h"
#include <vector>

using JobManager::Job;

struct QueueNode {
	QueueNode(Job* j) : job(j), next(nullptr) { }
	~QueueNode() { delete next; };
	Job* job;
	QueueNode* next;
};

// Internal data
static std::vector<std::unique_ptr<Thread>> threads;
static std::mutex queueLock;
static std::atomic<uint32_t> pending;
// Queue of jobs
static QueueNode* queueHead;
static QueueNode* queueTail;
// List of preallocated QueueEntries
static QueueNode* freeList;
static void processJobs();

void JobManager::initialize() {
	// Only initialize once
	static bool once = false;
	if (once) return;
	once = true;

	// Initialize queue and free list
	pending = 0u;
	queueHead = nullptr;
	queueTail = nullptr;
	freeList = nullptr;

	// Spawn worker threads, leave one core for the main thread
	auto nThreads = std::thread::hardware_concurrency() - 1;
	while (nThreads > 0) {
		threads.emplace_back(std::make_unique<Thread>(processJobs));
		nThreads--;
	}
}

void JobManager::shutdown() {
	delete queueHead;	// Destructor will recurse through linked list
	delete freeList;	// Destructor will recurse through linked list
}

static QueueNode* createQueueNode(Job* job) {
	if (freeList) {
		// Theres already one allocated
		QueueNode* node = freeList;
		freeList = node->next;
		new (node) QueueNode(job);
	}
	return new QueueNode(job);
}

static void freeQueueNode(QueueNode* node) {
	node->next = freeList;
	freeList = node;
}

void JobManager::addJob(Job* job) {
	// Enter critical section, will be released by destructor
	std::lock_guard<std::mutex> lock(queueLock);
	QueueNode* node = createQueueNode(job);
	if (queueHead == nullptr) {
		queueHead = node;
		queueTail = node;
	}
	else {
		queueTail->next = node;
	}
	pending++;
	for (auto& thread : threads)
		thread->signal();
}

static Job* dequeue() {
	// Enter critical section, will be released by destructor
	std::lock_guard<std::mutex> lock(queueLock);
	if (queueHead == nullptr)
		return nullptr;
	Job* job = queueHead->job;
	if (queueHead == queueTail) {
		freeQueueNode(queueHead);
		queueHead = nullptr;
		queueTail = nullptr;
	} else {
		QueueNode* temp = queueHead;
		queueHead = temp->next;
		freeQueueNode(temp);
	}
	return job;
}

static void processJobs() {
	Job* job = dequeue();
	while (job) {
		job->execute();
		pending--;
		job = dequeue();
	}
}

void JobManager::wait() {
	while (hasPending())
		processJobs();
}

bool JobManager::hasPending() {
	return (pending > 0);
}