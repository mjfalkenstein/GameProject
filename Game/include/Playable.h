#pragma once

#include "Character.h"
#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Stats.h"
#include "Consumable.h"

enum Direction {N = 0,
				NE = 1,
				E = 2,
				SE = 3,
				S = 4,
				SW = 5,
				W = 6,
				NW = 7};

class Playable : Character {

public:
	std::vector<Item> getInventory();
	void addItem(Item);
	void removeItem(Item);
	void equip(Item);
	Stats getStats();
	void move(Vec2f);
	void turn(Direction);
	void attack(Character);
	void use(Character, Consumable);

private:
	std::vector<Item> inventory;
	Weapon equipped;
	Stats stats;
};
