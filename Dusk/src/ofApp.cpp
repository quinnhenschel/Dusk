#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(30);

	
	//init environment
	environment.positionX = 0;
	environment.positionY = 0;
	environment.img.load("images/environment.png");

	
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


	//init enemy 
	enemy.positionX = 100;
	enemy.positionY = 400;

	enemy.img.load("images/characterStandingStill.png");


	//init player
	player.positionX = 640 - player.height / 2;
	player.positionY = 360 - player.width / 2;
	player.height = 150;
	player.width = 150;

	player.SetNumFrames(23);
	player.runningAnimation[0].load("images/characterAnimation/characterAnimation00001.png");
	player.runningAnimation[1].load("images/characterAnimation/characterAnimation00002.png");
	player.runningAnimation[2].load("images/characterAnimation/characterAnimation00003.png");
	player.runningAnimation[3].load("images/characterAnimation/characterAnimation00004.png");
	player.runningAnimation[4].load("images/characterAnimation/characterAnimation00005.png");
	player.runningAnimation[5].load("images/characterAnimation/characterAnimation00006.png");
	player.runningAnimation[6].load("images/characterAnimation/characterAnimation00007.png");
	player.runningAnimation[7].load("images/characterAnimation/characterAnimation00008.png");
	player.runningAnimation[8].load("images/characterAnimation/characterAnimation00009.png");
	player.runningAnimation[9].load("images/characterAnimation/characterAnimation00010.png");
	player.runningAnimation[10].load("images/characterAnimation/characterAnimation00011.png");
	player.runningAnimation[11].load("images/characterAnimation/characterAnimation00012.png");
	player.runningAnimation[12].load("images/characterAnimation/characterAnimation00013.png");
	player.runningAnimation[13].load("images/characterAnimation/characterAnimation00014.png");
	player.runningAnimation[14].load("images/characterAnimation/characterAnimation00015.png");
	player.runningAnimation[15].load("images/characterAnimation/characterAnimation00016.png");
	player.runningAnimation[16].load("images/characterAnimation/characterAnimation00017.png");
	player.runningAnimation[17].load("images/characterAnimation/characterAnimation00018.png");
	player.runningAnimation[18].load("images/characterAnimation/characterAnimation00019.png");
	player.runningAnimation[19].load("images/characterAnimation/characterAnimation00020.png");
	player.runningAnimation[20].load("images/characterAnimation/characterAnimation00021.png");
	player.runningAnimation[21].load("images/characterAnimation/characterAnimation00022.png");
	player.runningAnimation[22].load("images/characterAnimation/characterAnimation00023.png");

	player.standingStill.load("images/characterStandingStill.png");

}

//--------------------------------------------------------------
void ofApp::update(){

	bool noKeyDown = true;

	if (keyDown[OF_KEY_RIGHT] == true)
	{
		noKeyDown = false;
		player.direction = 1;
		player.lastFacing = 1;
		environment.positionX -= player.moveSpeed;

		if (key1.staticPosition == false){
			key1.positionX -= player.moveSpeed;
		}
		if (key2.staticPosition == false) {
			key2.positionX -= player.moveSpeed;
		}
		if (key3.staticPosition == false) {
			key3.positionX -= player.moveSpeed;
		}

		player.run();
	}

	if (keyDown[OF_KEY_LEFT] == true)
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

		player.run();
	}

	if (keyDown[OF_KEY_UP] == true)
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

		player.run();
	}

	if (keyDown[OF_KEY_DOWN] == true)
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

		player.run();
	}

	if (noKeyDown == true)
	{
		player.direction = 0;
	}

	//keys
	keyLogic();

}

//--------------------------------------------------------------
void ofApp::draw(){




	render.draw(&player, &enemy, &key1, &key2, &key3, &environment);


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










//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

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
