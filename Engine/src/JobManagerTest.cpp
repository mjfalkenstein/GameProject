#pragma once

#include "JobManager.h"
#include "EngineInternals.h"
#include <stdio.h>
#include <thread>
#include <chrono>

class TestJob1 : public JobManager::Job {
	virtual void execute() {
		printf("Starting TestJob1\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		printf("TestJob1 completed\n");
	}
} job1;

class TestJob2 : public JobManager::Job {
	virtual void execute() {
		printf("Starting TestJob2\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		printf("TestJob2 completed, adding TestJob1\n");
		JobManager::addJob(&job1);
	}
} job2;

int main() {
	JobManager::initialize();
	// add 100 job2's to the queue
	for (uint32_t i = 0; i < 100; i++)
		JobManager::addJob(&job2);
	JobManager::wait();
	JobManager::shutdown();
}

