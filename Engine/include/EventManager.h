#pragma once

#include <vector>
#include <functional>

namespace EventManager {

// Ignore this templated helper class
template<class T>
struct EventHelper {
	static std::vector<std::function<void(const T&)>> subscribers;
}; // Templates are pretty neat
template<class T>
std::vector<std::function<void(const T&)>> EventHelper<T>::subscribers;

// Subscribe to all events of type T
// Ex: subscribe<KeyEvent>(&keyHandler)
// NOTE: All events have to be a unique type, so probably
// just make a struct or something, Ex: if 2 events are
// int type then both will be treated as the same kind
template<class T>
void subscribe(std::function<void(const T&)> handler) {
	// TODO: check for duplicates, add unsubscribe(handler) function
	// TODO: lock sub/unsub functions for multithreading
	EventHelper<T>::subscribers.push_back(handler);
}

// Dispatch an event of type T to all of its subscribers
// Ex: dispatch<KeyEvent>(getKeyPressed())
template<class T>
void dispatch(const T& event) {
	for (auto& handler : EventHelper<T>::subscribers)
		handler(event);
}

}

// Used in testing, can be removed at some point
struct TestEvent {
	int value;
};
