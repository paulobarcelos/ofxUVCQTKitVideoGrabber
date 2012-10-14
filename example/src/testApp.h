#pragma once

#include "ofMain.h"
#include "ofxUVCQTKitVideoGrabber.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofxUVCQTKitVideoGrabber cam;
};
