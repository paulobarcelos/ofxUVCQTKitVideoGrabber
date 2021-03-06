#include "ofxUVCQTKitVideoGrabber.h"

const int ofxUVCQTKitVideoGrabber::CAMERAS_DATABASE[] = {
	// MICROSOFT_LIFECAM_HD_5000
	0x45e,0x76d,0x00,
	// MICROSOFT_LIFECAM_HD_3000
	0x45e,0x779,0x00,
	// ENCORE_ELECTRONICS_ENUCM_013
	0x1e4e,0x103,0x00,
	// ROSEWILL
	0x603,0x8b08,0x00,
	// BUILT_IN_ISIGHT
	0x5ac,0x8507,0x00,
	// LOGITECH_C910
	0x046d,0x821,0x02,
	// LOGITECH_C6260
	0x046d,0x81a,0x00
};

ofxUVCQTKitVideoGrabber::ofxUVCQTKitVideoGrabber(){
	controlHackWait = -1;
}
void ofxUVCQTKitVideoGrabber::setupControls(CameraModel model){
	int index = model * 3;
	setupControls(CAMERAS_DATABASE[index],
				  CAMERAS_DATABASE[index + 1],
				  CAMERAS_DATABASE[index + 2]);
}
void ofxUVCQTKitVideoGrabber::setupControls(int vendorId, int productId, int interfaceNum){
	controls.useCamera(vendorId, productId, interfaceNum);
}
void ofxUVCQTKitVideoGrabber::setupGui(string collectionName, string _filename, float x, float y){
	controlHackWait = 1;
	gui.setup(collectionName, _filename, x, y);
	
	ofxToggle * autoExposure = new ofxToggle();
	autoExposure->setup("Auto Exposure", false);
	autoExposure->addListener(this, &ofxUVCQTKitVideoGrabber::onAutoExposureChange);
	gui.add(autoExposure);
	
	ofxFloatSlider * exposure = new ofxFloatSlider();
	exposure->setup("Exposure", 0.2, 0, 1);
	exposure->addListener(this, &ofxUVCQTKitVideoGrabber::onExposureChange);
	gui.add(exposure);
	
	ofxToggle * autoFocus = new ofxToggle();
	autoFocus->setup("Auto Focus", false);
	autoFocus->addListener(this, &ofxUVCQTKitVideoGrabber::onAutoFocusChange);
	gui.add(autoFocus);
	
	ofxFloatSlider * focus = new ofxFloatSlider();
	focus->addListener(this, &ofxUVCQTKitVideoGrabber::onAbsoluteFocusChange);
	focus->setup("Focus", 0.5, 0, 1);
	
	gui.add(focus);
	
	ofxToggle * autoWB = new ofxToggle();
	autoWB->setup("Auto White Balance", false);
	gui.add(autoWB);
	
	ofxFloatSlider * wb = new ofxFloatSlider();
	wb->setup("White Balance", 0.5, 0, 1);
	wb->addListener(this, &ofxUVCQTKitVideoGrabber::onWhiteBalanceChange);
	gui.add(wb);
	
	ofxFloatSlider * gain = new ofxFloatSlider();
	gain->setup("Gain", 0.13, 0, 1);
	gain->addListener(this, &ofxUVCQTKitVideoGrabber::onGainChange);
	gui.add(gain);
	
	ofxFloatSlider * brightness = new ofxFloatSlider();
	brightness->setup("Brightness", 0.5, 0, 1);
	brightness->addListener(this, &ofxUVCQTKitVideoGrabber::onBrightnessChange);
	gui.add(brightness);
	
	ofxFloatSlider * contrast = new ofxFloatSlider();
	contrast->setup("Contrast", 0.13, 0, 1);
	contrast->addListener(this, &ofxUVCQTKitVideoGrabber::onContrastChange);
	gui.add(contrast);
	
	ofxFloatSlider * saturation = new ofxFloatSlider();
	saturation->setup("Saturation", 0.13, 0, 1);
	saturation->addListener(this, &ofxUVCQTKitVideoGrabber::onSaturationChange);
	gui.add(saturation);
	
	ofxFloatSlider * sharpness = new ofxFloatSlider();
	sharpness->setup("Sharpness", 0.2, 0, 1);
	sharpness->addListener(this, &ofxUVCQTKitVideoGrabber::onSharpnessChange);
	gui.add(sharpness);
	
	gui.loadFromFile(_filename);
}
void ofxUVCQTKitVideoGrabber::update(){
	ofxQTKitVideoGrabber::update();
	if(controlHackWait == 0){
		controlHackWait = -1;
		ofSleepMillis(5000);
		onAutoExposureChange(gui.getToggle("Auto Exposure"));
		onAutoFocusChange(gui.getToggle("Auto Focus"));
		onAutoWhiteBalanceChange(gui.getToggle("Auto White Balance"));
		onExposureChange(gui.getFloatSlider("Exposure"));
		onAbsoluteFocusChange(gui.getFloatSlider("Focus"));
		onWhiteBalanceChange(gui.getFloatSlider("White Balance"));
		onGainChange(gui.getFloatSlider("Gain"));
		onBrightnessChange(gui.getFloatSlider("Brightness"));
		onContrastChange(gui.getFloatSlider("Contrast"));
		onSaturationChange(gui.getFloatSlider("Saturation"));
		onSharpnessChange(gui.getFloatSlider("Sharpness"));
	}
	else if(controlHackWait > 0){
		controlHackWait--;
	}
	
	
}
void ofxUVCQTKitVideoGrabber::drawGui(){
	gui.draw();
}

ofxPanel& ofxUVCQTKitVideoGrabber::getGui(){
	return gui;
}
ofxUVC& ofxUVCQTKitVideoGrabber::getControls(){
	return controls;
}

void ofxUVCQTKitVideoGrabber::onAutoExposureChange(bool & enable){
	if(controlHackWait == -1)controls.setAutoExposure(enable);
}
void ofxUVCQTKitVideoGrabber::onExposureChange(float & value){
	if(controlHackWait == -1)controls.setExposure(1-value);
}

void ofxUVCQTKitVideoGrabber::onAutoFocusChange(bool & enable){
	if(controlHackWait == -1)controls.setAutoFocus(enable);
}
void ofxUVCQTKitVideoGrabber::onAbsoluteFocusChange(float & value){
	if(controlHackWait == -1)controls.setAbsoluteFocus(value);
}

void ofxUVCQTKitVideoGrabber::onAutoWhiteBalanceChange(bool & enable){
	if(controlHackWait == -1)controls.setAutoWhiteBalance(enable);
}
void ofxUVCQTKitVideoGrabber::onWhiteBalanceChange(float & value){
	if(controlHackWait == -1)controls.setWhiteBalance(value);
}

void ofxUVCQTKitVideoGrabber::onGainChange(float & value){
	if(controlHackWait == -1)controls.setGain(value);
}
void ofxUVCQTKitVideoGrabber::onBrightnessChange(float & value){
	if(controlHackWait == -1)controls.setBrightness(value);
}
void ofxUVCQTKitVideoGrabber::onContrastChange(float & value){
	if(controlHackWait == -1)controls.setContrast(value);
}
void ofxUVCQTKitVideoGrabber::onSaturationChange(float & value){
	if(controlHackWait == -1)controls.setSaturation(value);
}
void ofxUVCQTKitVideoGrabber::onSharpnessChange(float & value){
	if(controlHackWait == -1)controls.setSharpness(value);
}