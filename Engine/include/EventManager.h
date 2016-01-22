#pragma once

#include <vector>
#include <functional>

namespace EventManager {

// Ignore this templated helper class
template<class T>
class EventHelper {
public:	// tbh this is one of the most disgusting templates I've ever made
	typedef std::function<void(const T&)> Callback;
	std::vector<Callback> subscribers;
	static EventHelper<T>& get() {
		static EventHelper<T> instance;
		return instance;
	}
};

// Subscribe to all events of type T
// Ex: subscribe<KeyEvent>(&keyHandler)
// NOTE: All events have to be a unique type, so probably
// just make a struct or something, Ex: if 2 events are
// int type then both will be treated as the same kind
template<class T>
void subscribe(typename EventHelper<T>::Callback handler) {
	// TODO: check for duplicates, add unsubscribe(handler) function
	// TODO: lock sub/unsub functions for multithreading
	EventHelper<T>::get().subscribers.push_back(handler);
}

// Dispatch an event of type T to all of its subscribers
// Ex: dispatch<KeyEvent>(getKeyPressed())
template<class T>
void dispatch(const T& event) {
	for (auto& handler : EventHelper<T>::get().subscribers) {
		handler(event);
	}
}

}