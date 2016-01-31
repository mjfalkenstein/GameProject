#pragma once

#include "TileEnum.h"
#include "Sprite.h"

class Tile {

public:
	double movement;
	double cover;
	double protection;
	double concealment;
	double damage;
	double flamability;
	double rotation;
	Sprite* broken;
	Sprite* sprite;
	Sprite* border;
	Sprite* corner;
	Sprite* cover;

	void act();
	void changeSprite(TileEnum); //can't name it 'switch' 
	void breakTile(); //also can't name this 'break', reserved words are a bitch
	Tile(TileEnum);
};