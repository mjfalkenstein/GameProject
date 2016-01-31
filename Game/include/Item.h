#pragma once
#include "Sprite.h"

class Item {

public:
	Sprite sprite;
	int maxDurability;
	int durability;
	int value;
};