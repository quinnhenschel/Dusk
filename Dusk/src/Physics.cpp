#include "ofMain.h"
#include "Physics.h"
#include "Math.h"

Physics::Physics()
{
	black.r = 0;
	black.g = 0;
	black.b = 0;
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

void Physics::setCollisionMap(ofImage * collisionMap)
{
	collisionMapPixels = collisionMap->getPixels();

	for (int i = 0; i < collisionMap->getWidth(); i++)
	{
		for (int j = 0; j < collisionMap->getHeight(); j++)
		{
			ofColor c = collisionMapPixels.getColor(i, j);
			if (c == black)
			{
				obstacles[i][j] = false;
			}
			else 
			{
				obstacles[i][j] = true;
			}
		}
	}
}

