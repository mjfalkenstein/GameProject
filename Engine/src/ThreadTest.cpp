#include "Thread.h"
#include <stdio.h>
#include <string.h>

// This is just a silly test of the thread class
// An actual use case would be to add work to a queue
// and signal the thread when work is added, so that
// the thread isnt just constantly spinning

using Engine::Thread;
char buffer[512];

void command() {
	printf("Command called: %s\n");
}

int main() {
	Thread* thread = Thread::create(command);
	
	do {
		scanf_s("%s\n", buffer);
		thread->signal();
	} while (strcmp(buffer, "quit") != 0);

	delete thread;
}