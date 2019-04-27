#pragma once
#include "GameObject.h"
#include "AnimatedObject.h"
#include "Physics.h"

class Arrow : public GameObject
{
private:  //these canot be changed directly

public:
	Physics physics;

	int flightTime;
	int maxFlightTime;
	int arrowMoveSpeed;
	int startX;
	int startY;
	int endX;
	int endY;
	int differenceX;
	int differenceY;
	int distanceBetween;
	int framesToComplete;
	int incrimentX;
	int incrimentY;


	Arrow();
	~Arrow();

	void arrowFlying(AnimatedObject* player);
};