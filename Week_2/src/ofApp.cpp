#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofLogToConsole();

	gui.setup();

	nx.set("Number Cols", 100, 0, 500);
	ny.set("Number Rows", 100, 0, 500);
	col.set("Color", ofColor::black);

	img.load("image.png");

	gui.add(nx);
	gui.add(ny);
	gui.add(col);
	

}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetBackgroundColor(col);
	
	for (int ix = 0; ix < nx; ix++) {

		for (int iy = 0; iy < ny; iy++) {

			if ((ix % 2 == 0) || (iy % 2 == 0)) {
				ofNoFill();
			}
			else {
				ofFill();
			}

			int x = ((float)ix / nx) * img.getWidth();
			int y = ((float)iy / ny) * img.getHeight();

			//ofLogNotice() << x << ", " << y;

			ofColor col = img.getColor(x, y);

			ofSetColor(col);

			float ratio = ofGetWidth() / img.getWidth();

			x *= ratio;
			y *= ratio;

			ofDrawCircle(x, y, 3.0 * ratio);			
		}
	}
	//img.draw(0, 0, ofGetWidth(), img.getHeight() / img.getWidth()  * ofGetWidth());

	gui.draw();
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
