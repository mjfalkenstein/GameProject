#pragma once

#include <string>
#include "Vec2f.h"

class Entity {

public:
	std::string name;
	Vec2f getPosition();
	bool getVisible();
	bool getInteractive();
	void setPosition(Vec2f newPos);
	void setPosition(float x, float y);
	void setVisible(bool vis);
	void setInteractive(bool inter);
	virtual void update() = 0;

private:
	Vec2f position;
	bool isVisible;
	bool isInteractive;
};