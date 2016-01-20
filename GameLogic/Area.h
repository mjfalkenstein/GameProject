#pragma once

#include "Entity.h"

class Area {

public:
	float getWidth();
	float getHeight();
	void setWidth(float w);
	void setHeight(float h);

private:
	float width;
	float height;
	Area();
	Area(float w, float h);
	Area(const Area &toCopy);
};