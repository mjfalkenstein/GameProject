/*
 *	The JobManager provides a mechanism for parallel tasks to be queued
 *	and executed automatically, as well as ways to wait for all jobs to
 *	be completed
 *
 *	TODO:
 *	Add profiling hooks to jobs (remotery or vtune, or hand-written)
 *	Fit this into Engine namespace better.  e.g. EngineName::JobManager::Job
 *	Add a priority mechanism, so some jobs will be executed before others
 *	Add a dependency mechanism, so jobs can be added that require other jobs to finish first
 *		e.g. rendering requires all positions to be up-to-date, so the game logic and
 *		input handling jobs will have to complete first
 *	Add a job allocator that can re-use allocated jobs once they are done
 */

#pragma once

namespace JobManager {

// Interface for a job to be run in parallel
class Job {
public:
	// Put job execution code in this virtual function
	virtual void run() = 0;
};

// Adds a job to the queue,
void add(Job* job);

// Waits for all submitted jobs to be completed
void wait();

}