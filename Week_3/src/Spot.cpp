#include "Spot.h"


Spot::Spot()
{
}

void Spot::update() {
	x += 10 * ofSignedNoise(y, ofGetElapsedTimeMillis() / 100.0);
	y += 10 * ofSignedNoise(x, -(ofGetElapsedTimeMillis() / 100.0) );

	x = ofClamp(x, 0, ofGetWidth());
	y = ofClamp(y, 0, ofGetHeight());
}

void Spot::draw() {
	ofSetColor(col);
	ofDrawCircle(x, y, 10);
}

