#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Arrow.h"

class Render
{
public:
	int positionX;
	int positionY;

	Render();
	~Render();

	void determineGameObjectZ();
	void moveCamera();
	void draw(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, GameObject* key1, GameObject* key2, GameObject* key3, GameObject* environment, Arrow* arrow, GameObject* heart1, GameObject* heart2, GameObject* heart3, GameObject* startScreen, GameObject* winScreen, GameObject* loseScreen, int gameState, GameObject* tree, int tree_size);
	void drawArrow(GameObject* player, Arrow* arrow);
};