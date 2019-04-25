#pragma once
class GameObject
{
public:
	int positionX;
	int positionY;

	int moveSpeed;
	int direction;
	int lastFacing;
	int zIndex;

	bool staticPosition;

	int width;
	int height;
	ofImage img;

	GameObject();
	~GameObject();

	void Draw();
};