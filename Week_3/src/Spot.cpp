#include "Spot.h"


Spot::Spot(int x, int y, ofImage& img) : img(img)
{
	this->x = x;
	this->y = y;

	x = ofClamp(x, 0, img.getWidth());
	y = ofClamp(y, 0, img.getHeight());

	col = img.getColor(x, y);
}

void Spot::update() {

	x += 10 * ofSignedNoise(y, ofGetElapsedTimeMillis() / 100.0);
	y += 10 * ofSignedNoise(x, -(ofGetElapsedTimeMillis() / 100.0) );

	x = ofClamp(x, 0, img.getWidth());
	y = ofClamp(y, 0, img.getHeight());

	
	col = img.getColor(x, y);
}

void Spot::draw() {
	ofSetColor(col);
	ofDrawCircle(x, y, 10);
}

