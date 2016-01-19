

#pragma once

namespace JobManager {

// Interface for a job that can be added to the JobManager's
// work queue to be executed in parallel with other jobs
class Job {
public:
	// This function is called by the worker threads
	virtual void execute() = 0;
};

// Add a job to the work queue
void addJob(Job* job);

// Wait for all submitted jobs to complete
// In this function, the main thread will also consume jobs
void wait();

// Returns whether there are still jobs to do
bool hasPending();

}