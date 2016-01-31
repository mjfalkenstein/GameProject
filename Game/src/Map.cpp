#include "Map.h"

Map::Map(int width, int height) {
	w = width;
	h = height;
	groundTiles = new Tile*[width];
	for (int i = 0; i < width; ++i)
		groundTiles[i] = new Tile[height];

	decorations = new Tile*[width];
	for (int i = 0; i < width; ++i)
		decorations[i] = new Tile[height];

	airTiles = new Tile*[width];
	for (int i = 0; i < width; ++i)
		airTiles[i] = new Tile[height];
}

Map::Map() {
	w = 10;
	h = 10;
	Map(10, 10);
}

Map::~Map() {
	for (int i = 0; i < w; ++i)
		delete[] groundTiles[i];
	delete[] groundTiles;

	for (int i = 0; i < w; ++i)
		delete[] decorations[i];
	delete[] decorations;

	for (int i = 0; i < w; ++i)
		delete[] airTiles[i];
	delete[] airTiles;
}