#pragma once
#include "ofMain.h"

class Spot
{
public:
	Spot(int x, int y, ofImage& img);

	void update();
	void draw();

	ofColor col;

private:
	ofImage& img;

	int x;
	int y;
};

