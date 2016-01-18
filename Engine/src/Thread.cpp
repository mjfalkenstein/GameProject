#include "Thread.h"

namespace Engine {

Thread::Thread(std::function<void()> fn) : running(true), waiting(true) {
	delegate = fn;
	thread = std::thread(&Thread::run, this);
}

Thread::~Thread() {
	stop(); // Make sure the thread stops
	thread.join();
}

void Thread::signal() {
	condition.notify_all();
}

void Thread::stop() {
	running = false;
	signal();
}

bool Thread::isWaiting() {
	return waiting;
}

void Thread::run() {
	while (running) {
		// Sleep until signaled
		std::unique_lock<std::mutex> lock(mutex);
		condition.wait(lock);
		// Run once and repeat
		waiting = false;
		if (running) delegate();
		waiting = true;
	}
}

}