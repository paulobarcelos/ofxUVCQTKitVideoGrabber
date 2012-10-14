#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	// initialize the camera as you woulkd normaly do with ofxQTKitVideoGrabber
	cam.listDevices();
	cam.setDeviceID(1);
	cam.initGrabber(1280, 720);
	
	// Setup the controls matching the camera model.
	// You can use the registerd models, or initilize it manually
	// with setupControls(int vendorId, int productId, int interfaceNum)
	cam.setupControls(ofxUVCQTKitVideoGrabber::BUILT_IN_ISIGHT);
	// For advanced usage, use cam.getControl() to retrieve the ofxUVC object
	
	// Setup the gui (if you want it) with name, xml, x, y
	cam.setupGui("Camera Controls", "controls.xml", 20, 20);
	// For advanced usage, use getGui() to retrieve the ofxPanl object
	
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
