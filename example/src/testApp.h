#pragma once

#include "ofMain.h"
#include "ofxUCVQTKitVideoGrabber.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofxUCVQTKitVideoGrabber cam;
};
