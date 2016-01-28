#pragma once

#include "Entity.h"
#include "Character.h"
#include <functional>

class Area : Entity {

public:
	float getWidth();
	float getHeight();
	void setWidth(float w);
	void setHeight(float h);
	void setCallback(Character c, std::function<void()> f);	
	Area();
	Area(float w, float h);
	Area(const Area &toCopy);

private:
	float width;
	float height;
	std::function<void()> event;
	Character character;
};