#include "Character.h"

Sprite* Character::getSprite() {
	return &currentSprite;
}
float Character::getWidth() {
	return width;
}
float Character::getHeight() {
	return height;
}
int Character::getHealth() {
	return health;
}
void Character::setWidth(float w) {
	width = w;
}
void Character::setHeight(float h) {
	height = h;
}
void Character::setHealth(int h) {
	health = h;
}