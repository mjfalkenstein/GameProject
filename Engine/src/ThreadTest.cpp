#include "Thread.h"
#include <stdio.h>
#include <string.h>

// stop microsofts crusade against cstdlib (for scanf)
#pragma warning(disable: 4996)

// This is just a silly test of the thread class
// An actual use case would be to add work to a queue
// and signal the thread when work is added, so that
// the thread isnt just constantly spinning

char buffer[512];

void testThread() {
	printf("Command called: %s\n", buffer);
}

int main() {
	Engine::Thread thread(testThread);

	do {
		scanf("%s", buffer);
		thread.signal();
	} while (strcmp(buffer, "quit") != 0);

	return 0;
}