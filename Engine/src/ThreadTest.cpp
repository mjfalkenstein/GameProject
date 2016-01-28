#include "Thread.h"
#include "System.h"
#include "EventManager.h"
#include <string.h>

// Stop microsofts crusade against cstdlib (for scanf)
// I doubt buffer overruns will matter in this test
#pragma warning(disable: 4996)

// This is just a silly test of the thread class
// An actual use case would be to add work to a queue
// and signal the thread when work is added, so that
// the thread isn't constantly spinning without work

char buffer[512];

void testHandler2(const TestEvent& evt) {
	println("Event received by handler 2: ", evt.value);
}

void testThread() {
	static int counter = 0;
	println("Command called: ", (const char*)buffer);
	TestEvent e{ ++counter };
	EventManager::dispatch<TestEvent>(e);
}



// rename to main to test
int threadTest() {
	Thread thread(testThread);
	EventManager::subscribe<TestEvent>(&testHandler2);

	println("Enter a string, or \"quit\" to exit");
	do {
		scanf("%s", buffer);
		thread.signal();
	} while (strcmp(buffer, "quit") != 0);

	return 0;
}
