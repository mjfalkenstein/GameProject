#pragma once

#include "System.h"
#include "JobManager.h"
#include "EventManager.h"
#include "EngineInternals.h"

#include <thread>
#include <chrono>
#include <atomic>
#include <random>
#include <time.h>

std::atomic<int> counter = 0;
thread_local int thread_id = counter++;

struct OtherEvent {
	const char* str;
};

class TestJob1 : public JobManager::Job {
	virtual void execute() {
		println("Starting TestJob1 on thread ", thread_id);
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
		println("TestJob1 completed on thread ", thread_id);
		OtherEvent e{ "TestJob1 complete" };
		EventManager::dispatch(e);
	}
} job1;

class TestJob2 : public JobManager::Job {
	virtual void execute() {
		println("Starting TestJob2 on thread ", thread_id);
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
		println("TestJob2 completed on thread ", thread_id);
		OtherEvent e{ "TestJob2 complete" };
		EventManager::dispatch(e);
		JobManager::addJob(&job1);
	}
} job2;

void testHandler1(const TestEvent& event) {
	println("Event received by handler 1: ", event.value);
}

void otherHandler(const OtherEvent& event) {
	println("Message received: ", event.str);
}

int threadTest();

int main() {
	EventManager::subscribe<TestEvent>(&testHandler1);
	EventManager::subscribe<OtherEvent>(&otherHandler);
	
	TestEvent a{ 1 }, b{ 2 };
	EventManager::dispatch(a);
	EventManager::dispatch(b);

	println("Initializing on thread ", thread_id);
	srand((unsigned)time(0));
	system("pause");
	JobManager::initialize();
	// add 100 job2's to the queue
	for (int i = 0; i < 100; i++)
		JobManager::addJob(&job2);
	JobManager::wait();
	system("pause");
	JobManager::shutdown();

	return threadTest();
}

