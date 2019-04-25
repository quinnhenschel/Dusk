#pragma once
#include "GameObject.h"

class Key : public GameObject
{
private:  //these canot be changed directly



public:
	bool pickedUp;

	Key();
	~Key();

};