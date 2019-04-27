#pragma once
#include "AnimatedObject.h"

class Player : public AnimatedObject
{
public:
	int health;
	int numKeysCollected;
	int numKeysDelivered;

	ofImage armImg;
	ofImage armBackImg;

	ofImage arrowImg;
	ofImage cursorImg;

	Player();
	~Player();

	void move();
	void shootArrow();
	void pickup();
	void drawBackArm();
	void drawFrontArm();
	void drawCursor();
};