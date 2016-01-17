#include "Thread.h"
#include <mutex>
#include <thread>
#include <condition_variable>

using Engine::Thread;

class InternalThread : public Thread {
public:
	InternalThread(function cmd) : thread(execute, this) {
		command = cmd;
	}

	virtual void signal() {
		condition.notify_one();
	}

private:
	std::mutex mutex;
	std::thread thread;
	std::condition_variable condition;
	function command;

	void run() {
		while (true) {
			// Sleep until signaled
			std::unique_lock<std::mutex> lock(mutex);
			condition.wait(lock);
			// Run command once, then repeat
			command();
		}
	}

	static void execute(InternalThread* instance) {
		instance->run();
	}
};