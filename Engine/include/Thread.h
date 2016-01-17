#pragma once

namespace Engine {

class Thread {
public:
	typedef void(*function)(void);
	// TODO other functions
	virtual void signal() = 0;
	static Thread* create(function pred);
};

}