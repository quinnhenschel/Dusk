#pragma once

class Physics
{
public:
	ofPixels movementCollisionMap;
	ofPixels arrowCollisionMap;

	Physics();
	~Physics();

	//int checkDistance(objectX, objectY);
	//int getAngle(objectX, objectY);
	//void checkMapObstacles();
	//void checkArrowCollisions();
	//void checkObstacleDistance();
};