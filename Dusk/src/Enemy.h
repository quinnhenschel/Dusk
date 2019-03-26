#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	bool visibility;

	Enemy();
	~Enemy();

	void move();
	void detectPlayerRange();
	void attack();
	void enemyStateMachine();
};