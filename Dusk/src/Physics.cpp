#include "ofMain.h"
#include "Physics.h"
#include "Math.h"

Physics::Physics()
{
}

Physics::~Physics()
{
}

int Physics::checkDistance(int x1, int y1, int x2, int y2)
{
	int distanceX = x2 - x1;
	int distanceY = y2 - y1;

	int distance = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
	return distance;
}



//int Physics::getAngle(objectX, objectY)
//{
//	cout << "pew";
//}

