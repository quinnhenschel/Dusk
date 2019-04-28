#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "AnimatedObject.h"
#include "Player.h"
#include "Arrow.h"
#include "Enemy.h"
#include "Physics.h"
#include "Render.h"

#define COLLISION_DISTANCE 50

class ofApp : public ofBaseApp{

	public:
		Player player;
		Arrow arrow;

		Enemy enemy1;
		Enemy enemy2;
		Enemy enemy3;

		Render render;
		Physics physics;

		GameObject environment;
		ofImage collisionMap;

		GameObject tree[9];

		int gameState;
		GameObject startScreen;
		GameObject winScreen;
		GameObject loseScreen;


		GameObject key1;
		GameObject key2;
		GameObject key3;

		GameObject heart1;
		GameObject heart2;
		GameObject heart3;

		bool keyDown[255]; //all keys 

		void setup();
		void update();
		void draw();

		void keyLogic();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void keyReleased(int key);

};
