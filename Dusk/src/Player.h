#pragma once
#include "AnimatedObject.h"

class Player : public AnimatedObject
{
public:
	int health;
	int numKeysCollected;
	int numKeysDelivered;

	Player();
	~Player();

	void move();
	void shootArrow();
	void pickup();
};