#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "AnimatedObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Physics.h"
#include "Render.h"

#define COLLISION_DISTANCE 50

class ofApp : public ofBaseApp{

	public:
		Player player;
		Enemy enemy;
		Render render;
		Physics physics;

		GameObject environment;
		ofImage collisionMap;

		GameObject tree[9];

		GameObject key1;
		GameObject key2;
		GameObject key3;

		bool keyDown[255]; //all keys 

		void setup();
		void update();
		void draw();

		void keyLogic();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
