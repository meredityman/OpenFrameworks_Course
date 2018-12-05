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

	// Move dots randomly - Better
	x  += 2.0 * sin(ofNoise(x, y) - 0.5); 
	y  += 2.0 * sin(ofNoise(y, x) - 0.5);

	// Make sure x and y are within the image
	x = ofClamp(x, 0, img.getWidth());
	y = ofClamp(y, 0, img.getHeight());

	// Update the color
	col = img.getColor(x, y);
}

void Spot::draw() {
	ofSetColor(col);
	ofDrawCircle(x, y, 10);
}

