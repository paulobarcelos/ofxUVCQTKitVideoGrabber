#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
	cam.listDevices();
	cam.setDeviceID(0);
	cam.initGrabber(1280, 720);
	cam.setupControls(0x046d, 0x821, 0x02);
	cam.setupGui();
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	cam.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	cam.draw(0,0);
	cam.drawGui();
	
	
}
