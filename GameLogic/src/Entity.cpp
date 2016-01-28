#include "Entity.h"

Vec2f Entity::getPosition() {
	return position;
}

bool Entity::getVisible() {
	return isVisible;
}

bool Entity::getInteractive() {
	return isInteractive;
}

void Entity::setPosition(Vec2f newPos) {
	position = newPos;
}

void Entity::setPosition(float x, float y) {
	position = Vec2f(x, y);
}

void Entity::setVisible(bool vis) {
	isVisible = vis;
}

void Entity::setInteractive(bool inter) {
	isInteractive = inter;
}