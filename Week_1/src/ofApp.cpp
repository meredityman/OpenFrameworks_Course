#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(ofColor::white);

	ofSetColor(ofColor::black);


	float timeOffset = ofGetElapsedTimeMillis() / 200;

	int num = 50;
	float rad = 30;

	ofNoFill();
	for (int j = 0; j < num; j++) {
		rad += 5;

		if (j % 2 == 0) {
			ofNoFill();
		}
		else {
			ofFill();
		}


		for (int i = 0; i < num; i++) {

			float angle = glm::two_pi<float>() * i / num;
			angle += timeOffset;

			int x = rad * cos(angle) + ofGetWidth() * 0.5;
			int y = rad * sin(angle) + ofGetHeight() * 0.5;
			int w = 4.0;
			int h = 4.0;

		
			ofDrawRectangle(x, y, w, h);
		}
	}


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
