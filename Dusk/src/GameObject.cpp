#include "ofMain.h"
#include "GameObject.h"


GameObject::GameObject()
{
	positionX = positionY = 0;
	moveSpeed = 10;
	direction = 0;
	zIndex = 0;
	width = 60;
	height = 140;

}


GameObject::~GameObject()
{
}

void GameObject::Draw()
{
	img.draw(positionX, positionY);
}