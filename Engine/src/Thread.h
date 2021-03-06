/*
 *	Thread.h
 *	Kevin Jones
 *	A persistent thread class. Once started, it will wait until signaled,
 *	then call the delegate function, repeating until the stop function or
 *	destructor is called
 *	This is an internal class in the engine and not intended to be used
 *	directly, hence it being in the src directory
 */
#pragma once

// These really shouldnt need to be in the header
// M O D U L E S W H E N
#include <condition_variable>
#include <functional>
#include <thread>
#include <atomic>
#include <mutex>

class Thread {
public:
	// Creates and starts a thread
	Thread(std::function<void()> delegate);

	// Virtual destructor
	~Thread();

	// Signals the thread to stop waiting
	void signal();

	// Stops the thread as soon as the delegate is complete
	void stop();

	// Returns whether the thread is waiting for a signal
	// otherwise, it is somewhere in the run function
	bool isWaiting();

	// TODO other functions
private:
	// These also really shouldnt need to be in the header
	// Why can't I fully abstract this, bjarne
	std::mutex mutex;
	std::thread thread;
	std::atomic<bool> running;
	std::atomic<bool> waiting;
	std::function<void()> delegate;
	std::condition_variable condition;
	void run();
};