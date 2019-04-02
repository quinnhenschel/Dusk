#include "ofMain.h"
#include "AnimatedObject.h"


AnimatedObject::AnimatedObject()
{
	numFrames = 0;
	currentFrame = -1; //no valid frame
}

//frames[currentFrame].mirror(0, 1);

AnimatedObject::~AnimatedObject()
{
}

void AnimatedObject::run()
{
	if (numFrames > 0)
	{
		currentFrame++;
		cout << currentFrame++ << "\n";

		if (currentFrame >= numFrames)
			currentFrame = 0;
	}
}

void AnimatedObject::SetNumFrames(int n)
{
	if (n >= 0)
	{
		numFrames = n;
		if (n > 0)
			currentFrame = 0;
		else
			currentFrame = -1;
	}
}

void AnimatedObject::Animate()
{
	if (currentFrame >= 0)
	{
		if (direction == 0)
		{
			if (lastFacing == 2)
			{
				standingStill.mirror(0, 1);
				standingStill.draw(positionX, positionY);
				standingStill.mirror(0, 1);
			}
			else
			{
				standingStill.draw(positionX, positionY);
			}
		}
		else if (direction == 1)
		{
			runningAnimation[currentFrame].draw(positionX, positionY);
		}
		else if (direction == 2)
		{
			runningAnimation[currentFrame].mirror(0, 1);
			runningAnimation[currentFrame].draw(positionX, positionY);
			runningAnimation[currentFrame].mirror(0, 1);
		}

	}
}