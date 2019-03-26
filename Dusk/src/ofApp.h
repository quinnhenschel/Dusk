#pragma once

#include "ofMain.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Render.h"

class ofApp : public ofBaseApp{

	public:
		Player player;
		Enemy enemy;
		Render render;

		void setup();
		void update();
		void draw();

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
