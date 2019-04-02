#pragma once
#include "GameObject.h"

#define MAX_FRAMES 23

class AnimatedObject : public GameObject
{
private:  //these canot be changed directly
	int currentFrame;
	int numFrames;


public:
	ofImage runningAnimation[MAX_FRAMES];
	ofImage standingStill;

	AnimatedObject();
	~AnimatedObject();

	void run();
	void SetNumFrames(int n);
	void Animate();
};