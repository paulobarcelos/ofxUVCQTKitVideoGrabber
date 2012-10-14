#pragma once

#include "ofMain.h"
#include "ofxQTKitVideoGrabber.h"
#include "ofxUVC.h"
#include "ofxGui.h"

class ofxUCVQTKitVideoGrabber : public ofxQTKitVideoGrabber {
public:
	ofxUCVQTKitVideoGrabber();
	void update();
	void setupControls(int vendorId, int productId, int interfaceNum);
	void setupGui(string collectionName="", string _filename="settings.xml", float x = 10, float y = 10);
	
	void drawGui();
	
	ofxPanel& getGui();
	ofxUVC& getControl();

private:
	
	void onAutoExposureChange(bool & enable);
    void onExposureChange(float & value);
    
    void onAutoFocusChange(bool & enable);
    void onAbsoluteFocusChange(float & value);
    
    void onAutoWhiteBalanceChange(bool & enable);
    void onWhiteBalanceChange(float & value);
    
    void onGainChange(float & value);
    void onBrightnessChange(float & value);
    void onContrastChange(float & value);
    void onSaturationChange(float & value);
    void onSharpnessChange(float & value);	
	
	ofxUVC control;
	ofxPanel gui;
	
	int controlHackWait;
};