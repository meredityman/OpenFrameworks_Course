#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		
		class Spot {
		public:
			int x;
			int y;
			ofColor col;

			void draw() {
				ofSetColor(col);
				ofDrawCircle(x, y, 10);
			}

			void update() {
				x += 10 * ofSignedNoise(y, ofGetElapsedTimeMillis() / 100.0);
				y += 10 * ofSignedNoise(x, -(ofGetElapsedTimeMillis() / 100.0) );

				x = ofClamp(x, 0, ofGetWidth());
				y = ofClamp(y, 0, ofGetHeight());
			}
		};

		vector<Spot> spots;

};
