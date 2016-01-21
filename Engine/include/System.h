#pragma once

#include <string>
#include <mutex>

// TODO put print and println in some FileOutputStream class
// add other system features, like platform name detection, etc

// Expose string to the global namespace
typedef std::string String;
extern std::recursive_mutex printLock;

void print(const String& str);
void println(const String& str);
void print(const char* str);
void println(const char* str);

template <class T>
void print(const T& val) {
	std::lock_guard<std::recursive_mutex> lock(printLock);
	print(std::to_string(val));
}

template <class T>
void println(const T& val) {
	std::lock_guard<std::recursive_mutex> lock(printLock);
	println(std::to_string(val));
}

template <class T, class... Rest>
void print(const T& val, Rest... rest) {
	std::lock_guard<std::recursive_mutex> lock(printLock);
	print(val);
	print(rest...);
}

template <class T, class... Rest>
void println(const T& val, Rest... rest) {
	std::lock_guard<std::recursive_mutex> lock(printLock);
	print(val);
	println(rest...);
}
