#include "Thread.h"
#include <stdio.h>
#include <string.h>

// Stop microsofts crusade against cstdlib (for scanf)
// I doubt buffer overruns will matter in this test
#pragma warning(disable: 4996)

// This is just a silly test of the thread class
// An actual use case would be to add work to a queue
// and signal the thread when work is added, so that
// the thread isn't constantly spinning without work

char buffer[512];

void testThread() {
	printf("Command called: %s\n", buffer);
}

// rename to main to test
int threadTest() {
	Thread thread(testThread);

	printf("Enter a string, or \"quit\" to exit\n");
	do {
		scanf("%s", buffer);
		thread.signal();
	} while (strcmp(buffer, "quit") != 0);

	return 0;
}