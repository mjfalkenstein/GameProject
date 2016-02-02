#pragma once

#include "TileEnum.h"
#include "Sprite.h"

class Tile {

public:
	double movement = 1;
	double cover = 0;
	double protection = 0;
	double concealment = 0;
	double damage = 0;
	double flamability = 0;
	double rotation = 0;
	Sprite* broken;
	Sprite* sprite;
	Sprite* border;
	Sprite* corner;
//	Sprite* cover; cant name this the same thing
	TileEnum tileType;

	void act();
	void changeSprite(TileEnum); //can't name it 'switch' 
	void breakTile(); //also can't name this 'break', reserved words are a bitch
	Tile(TileEnum);
	Tile() : Tile(TileEnum::GRASS) { /* default constructor */ }
};