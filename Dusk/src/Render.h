#pragma once
#include "Player.h"
#include "Enemy.h"

class Render
{
public:
	int positionX;
	int positionY;

	Render();
	~Render();

	void determineGameObjectZ();
	void moveCamera();
	void draw(Player* player, Enemy* enemy);

};