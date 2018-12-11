#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	loadImage();


}

//--------------------------------------------------------------
void ofApp::loadImage() {
	ofFileDialogResult result = ofSystemLoadDialog("Load image... :)", false);


	// Check if dialog has returned a file
	if (result.bSuccess) {
		bool success = input_image.load(result.getPath());

		// Check if file was loaded into an image
		if (!success) {
			loadImage();
		}
		else {
			ofLogNotice() << "Loaded Image: " << result.fileName;
		}
	}
	else {
		loadImage();
	}
}

//--------------------------------------------------------------
void ofApp::saveImage() {
	ofFileDialogResult result = ofSystemSaveDialog("image.jpg", "Save Image");

	if (result.bSuccess) {

		output_image.setFromPixels(pixels);

		bool success = output_image.save(result.getPath());

		if (success) {
			ofLogNotice() << "Successfuly saved " << result.getName();
		}
	}
}


//--------------------------------------------------------------
void ofApp::update(){

	pixels = input_image.getPixels();

	for (int y = 0; y < pixels.getHeight(); y++) {

		for (int x = 0; x < pixels.getWidth(); x++) {
			//ofColor origonalColor = pixels.getColor(x, y);

			//int xr = x * y / 100.0;
			//int yr = x * y / 100.0;


			//yr = ofClamp(yr, 0, input_image.getHeight() - 1);
			//xr = ofClamp(xr, 0, input_image.getWidth() - 1);
			//ofColor warpedColor = input_image.getColor(xr, yr);

			//warpedColor.lerp(origonalColor, sin(ofGetElapsedTimeMillis()) );

			//pixels.setColor(x, y, warpedColor);

			//if (y % 2 == 0) {
			//	pixels.setColor(x, y, ofColor::black);
			//}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	int w = ofGetWidth() * 0.5;
	int h = w * input_image.getHeight() / input_image.getWidth();

	input_image.draw(0, 0, w, h );

	output_image.setFromPixels(pixels);

	output_image.draw(w, 0, w, h);
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
