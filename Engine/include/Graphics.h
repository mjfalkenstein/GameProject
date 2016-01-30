#pragma once

#include "System.h"

// The graphics API for this engine is very simplified,
// Currently, only sprites are supported, more features
// will be added as they are needed

namespace Graphics {

	class Spritesheet;

	class Sprite {
		Spritesheet* origin;	// The spritesheet containing the sprite
		int x, y;				// The position in the spritesheet
	};

	// Load a sprite sheet with tilesX by tilesY sprites
	Spritesheet* loadSpriteSheet(const String& filename, int tilesX, int tilesY);



}