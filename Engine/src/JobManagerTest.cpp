#pragma once

#include "System.h"
#include "JobManager.h"
#include "EngineInternals.h"

#include <thread>
#include <chrono>
#include <atomic>
#include <random>
#include <time.h>

std::atomic<int> counter = 0;
thread_local int thread_id = counter++;

class TestJob1 : public JobManager::Job {
	virtual void execute() {
		println("Starting TestJob1 on thread ", thread_id);
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
		println("TestJob1 completed on thread ", thread_id);
	}
} job1;

class TestJob2 : public JobManager::Job {
	virtual void execute() {
		println("Starting TestJob2 on thread ", thread_id);
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
		println("TestJob2 completed on thread ", thread_id);
		JobManager::addJob(&job1);
	}
} job2;

int main() {
	println("Initializing on thread ", thread_id);
	srand(time(0));
	system("pause");
	JobManager::initialize();
	// add 100 job2's to the queue
	for (uint32_t i = 0; i < 100; i++)
		JobManager::addJob(&job2);
	JobManager::wait();
	system("pause");
	JobManager::shutdown();
}

