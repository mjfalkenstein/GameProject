JobManager allows for scheduling jobs to occur in parallel and waiting for them to be completed

API:

class Job {
  virtual void execute() = 0;
};

void JobManager::AddJob(Job* job); // Adds a job to the queue
void JobManager::AddJob(Job* job, int priority);  // Adds a job to the queue, skipping lower priority jobs
void JobManager::AwaitCompletion(); // Waits until all queued jobs complete

Internals:
Initialized by Engine at startup, spawns as many worker threads as cores
Worker threads sleep until jobs are added, then they are signaled and they will process jobs from the queue
If priority ends up being supported, it will be implemented as a priority queue, otherwise a normal queue will suffice
Some mechanism should probably be added for preconditions, so jobs can be added that require one or more other jobs to finish first
