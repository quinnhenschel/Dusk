#include "ofMain.h"
#include "Render.h"


Render::Render()
{
}

Render::~Render()
{
}

void Render::determineGameObjectZ()
{
	cout << "move";
}

void Render::moveCamera()
{
	cout << "pew";
}

void Render::draw(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3, GameObject* key1, GameObject* key2, GameObject* key3, GameObject* environment, Arrow* arrow, GameObject* heart1, GameObject* heart2, GameObject* heart3, GameObject* startScreen, GameObject* winScreen, GameObject* loseScreen, int gameState)
{
	environment->Draw();
	
	key1->Draw();
	key2->Draw();
	key3->Draw();

	heart1->Draw();
	heart2->Draw();
	heart3->Draw();

	enemy1->Animate();
	enemy2->Animate();
	enemy3->Animate();

	drawArrow(player, arrow);
	player->drawBackArm();
	player->Animate();
	player->drawFrontArm();

	player->drawCursor();

	if (gameState == 0) {
		startScreen->Draw();
	}
	if (gameState == 1) {
		startScreen->positionX = 2000;
		startScreen->positionY = 2000;
	}
	if (gameState == 2) {
		startScreen->positionX = 0;
		startScreen->positionY = 0;
		winScreen->Draw();
	}
	if (gameState == 3) {
		startScreen->positionX = 0;
		startScreen->positionY = 0;
		loseScreen->Draw();
	}
}

void Render::drawArrow(GameObject* player, Arrow* arrow) {
	ofPushMatrix();
	ofTranslate(arrow->positionX + 68, arrow->positionY + 60, 0);

	int distanceX;
	int distanceY;

	if (arrow->staticPosition == true) {
		distanceX = ofGetMouseX() - player->positionX;
		distanceY = ofGetMouseY() - player->positionY;
	}
	else {
		distanceX = arrow->endX - arrow->startX;
		distanceY = arrow->endY- arrow->startY;
	}

	float radians = atan2(distanceX, distanceY);
	float angle = radians * 180 / 3.14;

	if (angle < 0) {
		angle = 360 + angle;
	}

	ofRotate(-angle + 90);
	ofTranslate(-(arrow->positionX + 68), -(arrow->positionY + 60), 0);
	arrow->Draw();
	ofPopMatrix();
}