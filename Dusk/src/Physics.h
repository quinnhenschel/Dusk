#pragma once

class Physics
{
public:
	ofPixels movementCollisionMap;
	ofPixels arrowCollisionMap;

	Physics();
	~Physics();

	int checkDistance(int x1, int y1, int x2, int y2);
	//int getAngle(objectX, objectY);
	//void checkMapObstacles();
	//void checkArrowCollisions();
	//void checkObstacleDistance();
};