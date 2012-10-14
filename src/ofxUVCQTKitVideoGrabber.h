#pragma once

#include "ofMain.h"
#include "ofxQTKitVideoGrabber.h"
#include "ofxUVC.h"
#include "ofxGui.h"

class ofxUVCQTKitVideoGrabber : public ofxQTKitVideoGrabber {
public:
	enum CameraModel {
		MICROSOFT_LIFECAM_HD_5000 = 0,
		MICROSOFT_LIFECAM_HD_3000,
		ENCORE_ELECTRONICS_ENUCM_013,
		ROSEWILL,
		BUILT_IN_ISIGHT,
		LOGITECH_C910,
		LOGITECH_C6260
	};
	
	ofxUVCQTKitVideoGrabber();
	void update();
	void setupControls(CameraModel model);
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
	
	static const int CAMERAS_DATABASE[]; // intialized in cpp	
};