#pragma once

class Physics
{
public:

	ofPixels collisionMapPixels;
	bool obstacles[3228][2236];
	ofColor black;

	Physics();
	~Physics();

	int checkDistance(int x1, int y1, int x2, int y2);
	void setCollisionMap(ofImage * collisionMap);

};