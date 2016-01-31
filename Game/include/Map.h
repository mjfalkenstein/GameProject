#pragma once

#include "Tile.h"

class Map {

public:
	int widh;
	int height;
	Tile **groundTiles;
	Tile **decorations;
	Tile **airTiles;

	Map(int, int);
	void act();
};