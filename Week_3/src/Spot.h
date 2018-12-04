#pragma once
#include "ofMain.h"

class Spot
{
public:
	Spot();

	void update();
	void draw();

	ofColor col;
	int x;
	int y;
};

