#include "ofMain.h"
#include "Enemy.h"


Enemy::Enemy()
{
	moving = false;
	animating = false;
	visibility = true;
	
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

Enemy::~Enemy()
{
}

void Enemy::move()
{
	cout << "move";
}

void Enemy::detectPlayerRange()
{
	cout << "detect";
}

bool Enemy::attack(Player* player)
{
	int distanceFromPlayer = physics.checkDistance(positionX, positionY, player->positionX, player->positionY);

	if (distanceFromPlayer < 60) {
		killEnemy();
		return true;
	}
	return false;
}

void Enemy::stateMachine(Player* player)
{	
	if (visibility == true) {
		if (physics.checkDistance(positionX, positionY, player->positionX, player->positionY) < 400) {
			if (abs(positionX - player->positionX) > 1) {
				moving = true;
				if (player->positionX > positionX) {
					direction = 1;
					lastFacing = 1;
					positionX += moveSpeed / 1.4;
					run();
				}
				else {
					direction = 2;
					lastFacing = 2;
					positionX -= moveSpeed / 1.4;
					run();
				}
			}
			else {
				moving = false;
			}

			if (abs(positionY - player->positionY) > 1) {
				if (player->positionY > positionY) {
					positionY += moveSpeed / 1.4;

					if (moving == false) {
						run();
					}

				}
				else {
					positionY -= moveSpeed / 1.4;

					if (moving == false) {
						run();
					}
				}
			}
		}
		else {
			if (abs(positionX - originalX) > 1) {
				moving = true;
				if (originalX > positionX) {
					direction = 1;
					lastFacing = 1;
					positionX += moveSpeed / 1.4;
					run();
				}
				else {
					direction = 2;
					lastFacing = 2;
					positionX -= moveSpeed / 1.4;
					run();
				}
			}
			else {
				moving = false;
			}

			if (abs(positionY - originalY) > 1) {
				if (originalY > positionY) {
					positionY += moveSpeed;

					if (moving == false) {
						run();
					}

				}
				else {
					positionY -= moveSpeed;

					if (moving == false) {
						run();
					}
				}
			}
		}
	}
}

void Enemy::checkArrowCollision(Arrow* arrow) 
{
	int distanceFromArrow = physics.checkDistance(positionX, positionY, arrow->positionX, arrow->positionY);

	if (distanceFromArrow < 60){
		positionX = -500;
		positionY = -500;
		visibility = false;
	}
}

void Enemy::killEnemy() {
	positionX = -500;
	positionY = -500;
	visibility = false;
}
