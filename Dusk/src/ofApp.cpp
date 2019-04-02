#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	player.positionX = 0;
	player.positionY = 200;

	enemy.positionX = 100;
	enemy.positionY = 400;


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

	enemy.img.load("images/characterStandingStill.png");

	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){

	bool noKeyDown = true;

	if (keyDown[OF_KEY_RIGHT] == true)
	{
		noKeyDown = false;
		player.direction = 1;
		player.lastFacing = 1;
		player.positionX += player.moveSpeed;
		player.run();
	}

	if (keyDown[OF_KEY_LEFT] == true)
	{
		noKeyDown = false;
		player.direction = 2;
		player.lastFacing = 2;
		player.positionX -= player.moveSpeed;
		player.run();
	}

	if (keyDown[OF_KEY_UP] == true)
	{
		noKeyDown = false;
		player.direction = player.lastFacing;
		player.positionY -= player.moveSpeed;
		player.run();
	}

	if (keyDown[OF_KEY_DOWN] == true)
	{
		noKeyDown = false;
		player.direction = player.lastFacing;
		player.positionY += player.moveSpeed;
		player.run();
	}

	if (noKeyDown == true)
	{
		player.direction = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	render.draw(&player, &enemy);
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
