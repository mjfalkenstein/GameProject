#pragma once

#include <string>
#include "Vec2f.h"

enum Direction {
	N = 0,
	NE = 1,
	E = 2,
	SE = 3,
	S = 4,
	SW = 5,
	W = 6,
	NW = 7
};

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