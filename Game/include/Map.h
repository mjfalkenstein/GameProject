#pragma once

#include "Tile.h"

class Map {

public:
	int w;
	int h;
	Tile **groundTiles;
	Tile **decorations;
	Tile **airTiles;

	Map(int, int);
	Map();
	~Map();
	void act();
};