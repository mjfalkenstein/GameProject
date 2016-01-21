#pragma once

#include "Entity.h"
#include "Sprite.h"
#include "Spritesheet.h"

class Character : Entity {

public:
	Sprite* getSprite();
	float getWidth();
	float getHeight();
	int getHealth();
	void setWidth(float);
	void setHeight(float);
	void setHealth(int);
	virtual void die();

private:
	Spritesheet spritesheet;
	Sprite currentSprite;
	float width;
	float height;
	int health;
	int maxHealth;
	bool isAlive;

};