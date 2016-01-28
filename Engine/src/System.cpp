#include "System.h"
#include <stdio.h>
#include <mutex>
#include <cstring>

std::recursive_mutex printLock;

void print(const String& str) {
	std::lock_guard<std::recursive_mutex> lock(printLock);
	fwrite(str.c_str(), 1, str.size(), stdout);
}

void println(const String& str) {
	std::lock_guard<std::recursive_mutex> lock(printLock);
	fwrite(str.c_str(), 1, str.size(), stdout);
	fputc('\n', stdout);
}

void print(const char* str) {
	std::lock_guard<std::recursive_mutex> lock(printLock);
	fwrite(str, 1, std::strlen(str), stdout);
}

void println(const char* str) {
	std::lock_guard<std::recursive_mutex> lock(printLock);
	fwrite(str, 1, std::strlen(str), stdout);
	fputc('\n', stdout);
}
