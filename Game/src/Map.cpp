#include "Map.h"

Map::Map(int width, int height) {
	groundTiles = new Tile*[width];
	for (int i = 0; i < width; ++i)
		Tile[i] = new Tile[height];

	decorations = new Tile*[width];
	for (int i = 0; i < width; ++i)
		Tile[i] = new Tile[height];

	airTiles = new Tile*[width];
	for (int i = 0; i < width; ++i)
		Tile[i] = new Tile[height];
}