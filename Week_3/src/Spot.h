#pragma once
#include "ofMain.h"

class Spot
{
public:
	Spot(int x, int y, ofImage& img);

	void update();
	void draw();

private:
	ofImage& img;

	ofColor col;
	int x;
	int y;
};

