#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Arrow.h"
#include "Physics.h"

class Enemy : public AnimatedObject
{
public:
	Physics physics;

	bool moving;
	int originalX;
	int originalY;
	bool animating;
	bool visibility;

	Enemy();
	~Enemy();

	void move();
	void detectPlayerRange();
	bool attack(Player* player);
	void stateMachine(Player* player);
	void checkArrowCollision(Arrow* arrow);
	void killEnemy();
};