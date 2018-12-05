#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//vid.setDeviceID(0);
	//vid.setDesiredFrameRate(60);
	//vid.initGrabber(1280, 720);

	vid.load("vid.mp4");
	vid.play();

	pixels.allocate(vid.getWidth(), vid.getHeight(), OF_PIXELS_RGBA);

}

//--------------------------------------------------------------
void ofApp::update(){
	vid.update();

	if (vid.isFrameNew()) {
		pixels = vid.getPixels();

		lines.clear();
		for (size_t y = 0; y < pixels.getHeight(); y += 6) {

			ofPolyline row;

			for (size_t x = 0; x < pixels.getWidth(); x++) {
				float offset = pixels.getColor(x, y).getBrightness();
				offset = ofMap(offset, 0, 255, -8, 8);

				row.addVertex(x, y + offset);
			}

			lines.push_back(row);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(ofColor::white);
	ofSetColor(ofColor::black);
	ofSetLineWidth(3.0);



	for (auto& line : lines) {
		line.draw();
	}


	//ofSetColor(ofColor::fromHsb(ofRandom(255), 255, 255));
	//ofSetLineWidth(4.0);
	//line.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'c') {
		line.clear();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	line.addVertex(x, y);
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
