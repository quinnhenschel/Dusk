#include "ofMain.h"
#include "Player.h"


Player::Player()
{
	armImg.load("images/characterArm.png");
	armBackImg.load("images/characterArmBack.png");
	cursorImg.load("images/cursor.png");
	
	health = 3;

	positionX = 640 - height / 2;
	positionY = 360 - width / 2;
	height = 150;
	width = 150;

	standingStill.load("images/characterStandingStill.png");

	SetNumFrames(23);
	runningAnimation[0].load("images/characterAnimation/characterAnimation00001.png");
	runningAnimation[1].load("images/characterAnimation/characterAnimation00002.png");
	runningAnimation[2].load("images/characterAnimation/characterAnimation00003.png");
	runningAnimation[3].load("images/characterAnimation/characterAnimation00004.png");
	runningAnimation[4].load("images/characterAnimation/characterAnimation00005.png");
	runningAnimation[5].load("images/characterAnimation/characterAnimation00006.png");
	runningAnimation[6].load("images/characterAnimation/characterAnimation00007.png");
	runningAnimation[7].load("images/characterAnimation/characterAnimation00008.png");
	runningAnimation[8].load("images/characterAnimation/characterAnimation00009.png");
	runningAnimation[9].load("images/characterAnimation/characterAnimation00010.png");
	runningAnimation[10].load("images/characterAnimation/characterAnimation00011.png");
	runningAnimation[11].load("images/characterAnimation/characterAnimation00012.png");
	runningAnimation[12].load("images/characterAnimation/characterAnimation00013.png");
	runningAnimation[13].load("images/characterAnimation/characterAnimation00014.png");
	runningAnimation[14].load("images/characterAnimation/characterAnimation00015.png");
	runningAnimation[15].load("images/characterAnimation/characterAnimation00016.png");
	runningAnimation[16].load("images/characterAnimation/characterAnimation00017.png");
	runningAnimation[17].load("images/characterAnimation/characterAnimation00018.png");
	runningAnimation[18].load("images/characterAnimation/characterAnimation00019.png");
	runningAnimation[19].load("images/characterAnimation/characterAnimation00020.png");
	runningAnimation[20].load("images/characterAnimation/characterAnimation00021.png");
	runningAnimation[21].load("images/characterAnimation/characterAnimation00022.png");
	runningAnimation[22].load("images/characterAnimation/characterAnimation00023.png");
}

Player::~Player()
{
}

void Player::move()
{
	cout << "move";
}

void Player::shootArrow()
{
	cout << "pew";
}
void Player::pickup()
{
	cout << "pickup";
}

void Player::drawFrontArm()
{
	ofPushMatrix();           
	ofTranslate(638, 390, 0);

	int distofCursorX = ofGetMouseX() - positionX;
	int distofCursorY = ofGetMouseY() - positionY;

	float radians = atan2(distofCursorX, distofCursorY);
	float angle = radians * 180 / 3.14;

	if (angle < 0) {
		angle = 360 + angle;
	}

	ofRotate(-angle + 90);        
	ofTranslate(-638, -390, 0);
	armImg.draw(positionX, positionY);       
	ofPopMatrix();               
	
}

void Player::drawBackArm()
{
	ofPushMatrix();
	ofTranslate(638, 390, 0);

	int distofCursorX = ofGetMouseX() - positionX;
	int distofCursorY = ofGetMouseY() - positionY;

	float radians = atan2(distofCursorX, distofCursorY);
	float angle = radians * 180 / 3.14;

	if (angle < 0) {
		angle = 360 + angle;
	}

	ofRotate(-angle + 90);
	ofTranslate(-638, -390, 0);
	armBackImg.draw(positionX, positionY);
	ofPopMatrix();

}


void Player::drawCursor()
{
	cursorImg.draw(ofGetMouseX() - 25, ofGetMouseY() - 25);
}

