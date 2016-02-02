#pragma once

#include "Tile.h"
#include "Grid.h"

class Map {

public:
	int width;
	int height;
	Grid<Tile> groundTiles;
	Grid<Tile> decorations;
	Grid<Tile> airTiles;

	Map(int, int);
	Map();
	~Map();
	void act();
};