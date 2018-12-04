#include "Spot.h"

// Constructor for Spot class
Spot::Spot(int x, int y, ofImage& img) : img(img)
{
	this->x = x; // Initialise x
	this->y = y; // Initialise y


	// Make sure x and y are within the image;
	x = ofClamp(x, 0, img.getWidth());
	y = ofClamp(y, 0, img.getHeight());

	col = img.getColor(x, y);
}

void Spot::update() {

	// Move the dot randomly
	x += 10 * ofSignedNoise(y, ofGetElapsedTimeMillis() / 100.0);
	y += 10 * ofSignedNoise(x, -(ofGetElapsedTimeMillis() / 100.0) );

	// Make sure x and y are within the image;
	x = ofClamp(x, 0, img.getWidth());
	y = ofClamp(y, 0, img.getHeight());

	// Update the color
	col = img.getColor(x, y);
}

void Spot::draw() {
	ofSetColor(col);
	ofDrawCircle(x, y, 10);
}

