#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLogToConsole();
	loadImage();
}
//--------------------------------------------------------------
void ofApp::loadImage() {
	auto result = ofSystemLoadDialog("Select an image...");

	if (result.bSuccess) {
		if (!input_image.load(result.getPath())) {
			loadImage();
		}
		else {
			output_pixels = input_image.getPixels();
		}
	}
	else {
		loadImage();
	}
}
//--------------------------------------------------------------
void ofApp::saveImage() {
	auto result = ofSystemSaveDialog("image.jpg", "Save image...");

	if (result.bSuccess) {
		output_image.setFromPixels(output_pixels);
		output_image.save(result.getPath());
	}
}
//--------------------------------------------------------------
bool ofApp::sortFunction(ofColor a, ofColor b) {
	return a.r > b.r;
}

//--------------------------------------------------------------
void ofApp::update(){

	output_pixels = input_image.getPixels();
	for (int y = 0; y < output_pixels.getHeight(); y++) {
		vector<ofColor> colors;
		bool inSequence = false;
		vector<int> start;
		vector<int> stop;

		for (int x = 0; x < output_pixels.getWidth(); x++) {
			ofColor& col = input_image.getColor(x, y);

			colors.push_back(input_image.getColor(x, y));

			if (!inSequence && col.getBrightness() > 200) {
				start.push_back(x);
				inSequence = true;
			}
			if (inSequence && col.getBrightness() < 200) {
				stop.push_back(x);
				inSequence = false;
			}
		}
		if (inSequence) stop.push_back(output_pixels.getWidth());

		for (int i = 0; i < start.size(); i++) {
			//ofLogNotice() << start[i] << ", " << stop[i];
			std::sort(colors.begin() + start[i], colors.begin() + stop[i], sortFunction);
		}
		
		for (int x = 0; x < output_pixels.getWidth(); x++) {
			output_pixels.setColor(x, y, colors[x]);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	output_image.setFromPixels(output_pixels);

	output_image.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 's':
		saveImage();
		break;
	case 'l':
		loadImage();
		break;
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
