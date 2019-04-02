#include "ofMain.h"
#include "Physics.h"

Physics::Physics()
{
	black.r = 0;
	black.g = 0;
	black.b = 0;

	white.r = 255;
	white.g = 255;
	white.b = 255;

}

Physics::~Physics()
{
}

void Physics::setMovementMap(ofImage * map)
{
	pixels = map->getPixels();

	for (int j = 0; j < map->getHeight(); j++)
	{
		for (int i = 0; i < map->getWidth(); i++)
		{		
			c = pixels.getColor(j,i);
			if (c == black)
			{
				movementMap[j][i] = 1;
			}
			else if (c == white)
			{
				movementMap[j][i] = 0;
			}
		}
	}
}

//int Physics::checkDistance(objectX, objectY)
//{
//	cout << "move";
//}
//
//int Physics::getAngle(objectX, objectY)
//{
//	cout << "pew";
//}
