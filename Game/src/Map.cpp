#include "Map.h"

Map::Map(int w, int h) : groundTiles(width, height), decorations(width, height), airTiles(width, height){
	width = w;
	height = h;
}

Map::Map() : groundTiles(0, 0), decorations(0, 0), airTiles(0, 0) {
	width = 0;
	height = 0;
}