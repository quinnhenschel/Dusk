#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(30);
	ofHideCursor();
	
	//init environment
	environment.positionX = -1000;
	environment.positionY = -1250;
	environment.img.load("images/environment.jpg");

	//load start and end screen
	startScreen.positionX = winScreen.positionX = loseScreen.positionX = 0;
	startScreen.positionY = winScreen.positionY = loseScreen.positionY = 0;
	startScreen.img.load("images/startOverlay.png");
	winScreen.img.load("images/winOverlay.png");
	loseScreen.img.load("images/loseOverlay.png");
	gameState = 0;

	//init hearts
	heart1.positionX = 1100;
	heart1.positionY = 50;
	heart1.img.load("images/heart.png");

	heart2.positionX = 1150;
	heart2.positionY = 50;
	heart2.img.load("images/heart.png");

	heart3.positionX = 1200;
	heart3.positionY = 50;
	heart3.img.load("images/heart.png");

	//init keys
	key1.positionX = 300;
	key1.positionY = 300;
	key1.img.load("images/key1.png");
	key1.staticPosition = false;
	key2.positionX = 400;
	key2.positionY = 500;
	key2.img.load("images/key2.png");
	key2.staticPosition = false;
	key3.positionX = 200;
	key3.positionY = 600;
	key3.img.load("images/key3.png");
	key3.staticPosition = false;
	key1.height = key1.width = key2.height = key2.width = key3.height = key3.width = 50;

	//init enemy positions 
	enemy1.positionX = enemy1.originalX = 1450;
	enemy1.positionY = enemy1.originalY = -550;
	
	enemy2.positionX = enemy2.originalX = 620;
	enemy2.positionY = enemy2.originalY = -230;

	enemy3.positionX = enemy3.originalX = 0;
	enemy3.positionY = enemy3.originalY = 0;

	//init arrow position (attatched to the player)
	arrow.positionX = player.positionX;
	arrow.positionY = player.positionY;

}

//--------------------------------------------------------------
void ofApp::update(){

	cout << environment.positionX + player.positionX;
	cout << "\n";
	cout << environment.positionY + player.positionY;
	cout << "\n";
	cout << "\n";

	//Move the map, keys and enemy at negative player movement speed. Gives the illusion of camera movement.
	bool noKeyDown = true;

	if (keyDown['d'] == true)
	{


		noKeyDown = false;
		player.direction = 1;
		player.lastFacing = 1;
		environment.positionX -= player.moveSpeed;

		if(key1.staticPosition == false){
			key1.positionX -= player.moveSpeed;
		}
		if(key2.staticPosition == false){
			key2.positionX -= player.moveSpeed;
		}
		if(key3.staticPosition == false){
			key3.positionX -= player.moveSpeed;
		}
		if(arrow.staticPosition == false){
			arrow.positionX -= player.moveSpeed;
		}
		if(enemy1.staticPosition == false){
			enemy1.positionX -= player.moveSpeed;
			enemy1.originalX -= player.moveSpeed;
		}
		if (enemy2.staticPosition == false) {
			enemy2.positionX -= player.moveSpeed;
			enemy2.originalX -= player.moveSpeed;
		}
		if (enemy3.staticPosition == false) {
			enemy3.positionX -= player.moveSpeed;
			enemy3.originalX -= player.moveSpeed;
		}


		player.run();
	}

	if (keyDown['a'] == true)
	{


		noKeyDown = false;
		player.direction = 2;
		player.lastFacing = 2;
		environment.positionX += player.moveSpeed;

		if (key1.staticPosition == false) {
			key1.positionX += player.moveSpeed;
		}
		if (key2.staticPosition == false) {
			key2.positionX += player.moveSpeed;
		}
		if (key3.staticPosition == false) {
			key3.positionX += player.moveSpeed;
		}
		if (arrow.staticPosition == false) {
			arrow.positionX += player.moveSpeed;
		}
		if (enemy1.staticPosition == false) {
			enemy1.positionX += player.moveSpeed;
			enemy1.originalX += player.moveSpeed;
		}
		if (enemy2.staticPosition == false) {
			enemy2.positionX += player.moveSpeed;
			enemy2.originalX += player.moveSpeed;
		}
		if (enemy3.staticPosition == false) {
			enemy3.positionX += player.moveSpeed;
			enemy3.originalX += player.moveSpeed;
		}

		player.run();
	}

	if (keyDown['w'] == true)
	{


		noKeyDown = false;
		player.direction = player.lastFacing;
		environment.positionY += player.moveSpeed;

		if (key1.staticPosition == false) {
			key1.positionY += player.moveSpeed;
		}
		if (key2.staticPosition == false) {
			key2.positionY += player.moveSpeed;
		}
		if (key3.staticPosition == false) {
			key3.positionY += player.moveSpeed;
		}
		if (arrow.staticPosition == false) {
			arrow.positionY += player.moveSpeed;
		}
		if (enemy1.staticPosition == false) {
			enemy1.positionY += player.moveSpeed;
			enemy1.originalY += player.moveSpeed;
		}
		if (enemy2.staticPosition == false) {
			enemy2.positionY += player.moveSpeed;
			enemy2.originalY += player.moveSpeed;
		}
		if (enemy3.staticPosition == false) {
			enemy3.positionY += player.moveSpeed;
			enemy3.originalY += player.moveSpeed;
		}

		if (keyDown['d'] == false && keyDown['a'] == false) {
			player.run();
		}
		
	}

	if (keyDown['s'] == true)
	{


		noKeyDown = false;
		player.direction = player.lastFacing;
		environment.positionY -= player.moveSpeed;

		if (key1.staticPosition == false) {
			key1.positionY -= player.moveSpeed;
		}
		if (key2.staticPosition == false) {
			key2.positionY -= player.moveSpeed;
		}
		if (key3.staticPosition == false) {
			key3.positionY -= player.moveSpeed;
		}
		if (arrow.staticPosition == false) {
			arrow.positionY -= player.moveSpeed;
		}
		if (enemy1.staticPosition == false) {
			enemy1.positionY -= player.moveSpeed;
			enemy1.originalY -= player.moveSpeed;
		}
		if (enemy2.staticPosition == false) {
			enemy2.positionY -= player.moveSpeed;
			enemy2.originalY -= player.moveSpeed;
		}
		if (enemy3.staticPosition == false) {
			enemy3.positionY -= player.moveSpeed;
			enemy3.originalY -= player.moveSpeed;
		}

		if (keyDown['d'] == false && keyDown['a'] == false) {
			player.run();
		}
	}

	if (noKeyDown == true)
	{
		player.direction = 0;
	}

	//On mouse click fire arrow if its not already in the air
	if (arrow.staticPosition == false){
		arrow.arrowFlying(&player);
		enemy1.checkArrowCollision(&arrow);
		enemy2.checkArrowCollision(&arrow);
		enemy3.checkArrowCollision(&arrow);
	}

	//Update enemies
	enemy1.stateMachine(&player);
	enemy2.stateMachine(&player);
	enemy3.stateMachine(&player);

	if (enemy1.attack(&player) == true) {
		enemy1.killEnemy();
		player.health -= 1;
	}
	if (enemy2.attack(&player) == true) {
		enemy2.killEnemy();
		player.health -= 1;
	}
	if (enemy3.attack(&player) == true) {
		enemy3.killEnemy();
		player.health -= 1;
	}

	//Update health
	if (player.health == 2) {
		heart1.positionY = -200;
	}
	if (player.health == 1) {
		heart2.positionY = -200;
	}
	if (player.health == 0) {
		heart3.positionY = -200;
		gameState = 3;
	}

	//Update keys
	keyLogic();
	
	cout << "\n";
	cout << environment.positionX;
	cout << "\n";


	//check for a win
	if (key1.staticPosition == true && key2.staticPosition == true && key3.staticPosition == true && environment.positionY > -100 && -800 > environment.positionX && environment.positionX > -1200) {
		gameState = 2;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	render.draw(&player, &enemy1, &enemy2, &enemy3, &key1, &key2, &key3, &environment, &arrow, &heart1, &heart2, &heart3, &startScreen, &winScreen, &loseScreen, gameState);
}

void ofApp::keyLogic(){

	if (physics.checkDistance(player.positionX + (player.width / 2), player.positionY + (player.height / 2), key1.positionX + (key1.width / 2), key1.positionY + (key1.height / 2)) < COLLISION_DISTANCE){
		cout << "key 1\n";
		key1.positionX = 50;
		key1.positionY = 50;
		key1.staticPosition = true;
	}

	if (physics.checkDistance(player.positionX + (player.width / 2), player.positionY + (player.height / 2), key2.positionX + (key2.width / 2), key2.positionY + (key2.height / 2)) < COLLISION_DISTANCE) {
		cout << "key 2\n";
		key2.positionX = 100;
		key2.positionY = 50;
		key2.staticPosition = true;
	}

	if (physics.checkDistance(player.positionX + (player.width / 2), player.positionY + (player.height / 2), key3.positionX + (key3.width / 2), key3.positionY + (key3.height / 2)) < COLLISION_DISTANCE) {
		cout << "key 3\n";
		key3.positionX = 150;
		key3.positionY = 50;
		key3.staticPosition = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	keyDown[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	keyDown[key] = false;
}


void ofApp::mousePressed(int x, int y, int button) {
	arrow.startX = player.positionX;
	arrow.startY = player.positionY;
	arrow.endX = ofGetMouseX();
	arrow.endY = ofGetMouseY();
	arrow.staticPosition = false;

	if (gameState == 0) {
		gameState = 1;
	}
}







//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
