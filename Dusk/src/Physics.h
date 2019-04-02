#pragma once

class Physics
{
public:
	//ofPixels movementCollisionMap;
	//ofPixels arrowCollisionMap;

	Physics();
	~Physics();

	int movementMap[mapHeight][mapWidth];
	ofColor black;
	ofColor white;
	ofColor c;
	ofPixels pixels;

	void setMovementMap(ofImage * map);

	//int checkDistance(objectX, objectY);
	//int getAngle(objectX, objectY);
	//void checkMapObstacles();
	//void checkArrowCollisions();
	//void checkObstacleDistance();
};