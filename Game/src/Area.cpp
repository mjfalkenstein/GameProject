#include "Area.h"

Area::Area() : width(0.0f), height(0.0f) { }

Area::Area(float w, float h) : width(h), height(h) { }

Area::Area(const Area &a) : width(a.width), height(a.height) { }

float Area::getWidth() {
	return width;
}

float Area::getHeight() {
	return height;
}

void Area::setWidth(float w) {
	width = w;
}

void Area::setHeight(float h) {
	height = h;
}

void Area::setCallback(Character* c, std::function<void()> f) {
	character = c;
	event = f;
}

void update() {
//	if (contains(character)) {
//		if(event)
//			event();
//	}
}