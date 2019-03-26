#pragma once
#include "GameObject.h"

class Player : public GameObject
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