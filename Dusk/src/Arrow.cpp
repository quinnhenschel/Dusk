#include "ofMain.h"
#include "Arrow.h"

Arrow::Arrow()
{
	maxFlightTime = 24;
	flightTime = 0;
	arrowMoveSpeed = 30;
	img.load("images/arrow.png");
	staticPosition = true;
}

Arrow::~Arrow()
{

}

void Arrow::arrowFlying(AnimatedObject* player)
{
	flightTime++;

	differenceX = endX - startX;
	differenceY = endY - startY;

	distanceBetween = physics.checkDistance(startX, startY, endX, endY);

	framesToComplete = distanceBetween / arrowMoveSpeed;
	if (framesToComplete < 0) {
		framesToComplete = framesToComplete * -1;
	}

	incrimentX = differenceX / framesToComplete;
	incrimentY = differenceY / framesToComplete;

	positionX = positionX + incrimentX;
	positionY = positionY + incrimentY;


	if (flightTime > maxFlightTime)
	{
		staticPosition = true;
		positionX = player->positionX;
		positionY = player->positionY;
		flightTime = 0;
	}
}

