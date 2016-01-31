#pragma once

#include "Character.h"
#include "Item.h"

class Consumable : Item {

public:
	void use(Character*);
};