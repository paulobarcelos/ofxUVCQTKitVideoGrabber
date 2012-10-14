#include "ofxUCVQTKitVideoGrabber.h"
ofxUCVQTKitVideoGrabber::ofxUCVQTKitVideoGrabber(){
	controlHackWait = 1;
}
void ofxUCVQTKitVideoGrabber::setupControls(int vendorId, int productId, int interfaceNum){
	control.useCamera(vendorId, productId, interfaceNum);
}
void ofxUCVQTKitVideoGrabber::setupGui(string collectionName, string _filename, float x, float y){
	gui.setup(collectionName, _filename, x, y);
	gui.loadFromFile(_filename);
	
	ofxToggle * autoExposure = new ofxToggle();
	autoExposure->setup("Auto Exposure", false);
	autoExposure->addListener(this, &ofxUCVQTKitVideoGrabber::onAutoExposureChange);
	gui.add(autoExposure);
	
	ofxFloatSlider * exposure = new ofxFloatSlider();
	exposure->setup("Exposure", 0.5, 0, 1);
	exposure->addListener(this, &ofxUCVQTKitVideoGrabber::onExposureChange);
	gui.add(exposure);
	
	ofxToggle * autoFocus = new ofxToggle();
	autoFocus->setup("Auto Focus", false);
	autoFocus->addListener(this, &ofxUCVQTKitVideoGrabber::onAutoFocusChange);
	gui.add(autoFocus);
	
	ofxFloatSlider * focus = new ofxFloatSlider();
	focus->setup("Focus", 1.0, 0, 1);
	focus->addListener(this, &ofxUCVQTKitVideoGrabber::onAbsoluteFocusChange);
	gui.add(focus);
	
	ofxToggle * autoWB = new ofxToggle();
	autoWB->setup("Auto White Balance", false);
	autoWB->addListener(this, &ofxUCVQTKitVideoGrabber::onAutoWhiteBalanceChange);
	gui.add(autoWB);
	
	ofxFloatSlider * wb = new ofxFloatSlider();
	wb->setup("White Balance", 0.5, 0, 1);
	wb->addListener(this, &ofxUCVQTKitVideoGrabber::onWhiteBalanceChange);
	gui.add(wb);
	
	ofxFloatSlider * gain = new ofxFloatSlider();
	gain->setup("Gain", 0.5, 0, 1);
	gain->addListener(this, &ofxUCVQTKitVideoGrabber::onGainChange);
	gui.add(gain);
	
	ofxFloatSlider * brightness = new ofxFloatSlider();
	brightness->setup("Brightness", 0.5, 0, 1);
	brightness->addListener(this, &ofxUCVQTKitVideoGrabber::onBrightnessChange);
	gui.add(brightness);
	
	ofxFloatSlider * contrast = new ofxFloatSlider();
	contrast->setup("Contrast", 0.13, 0, 1);
	contrast->addListener(this, &ofxUCVQTKitVideoGrabber::onContrastChange);
	gui.add(contrast);
	
	ofxFloatSlider * saturation = new ofxFloatSlider();
	saturation->setup("Saturation", 0.13, 0, 1);
	saturation->addListener(this, &ofxUCVQTKitVideoGrabber::onSaturationChange);
	gui.add(saturation);
	
	ofxFloatSlider * sharpness = new ofxFloatSlider();
	sharpness->setup("Sharpness", 0.2, 0, 1);
	gui.add(sharpness);
	
	
}
void ofxUCVQTKitVideoGrabber::update(){
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
void ofxUCVQTKitVideoGrabber::drawGui(){
	gui.draw();
}

ofxPanel& ofxUCVQTKitVideoGrabber::getGui(){
	return gui;
}
ofxUVC& ofxUCVQTKitVideoGrabber::getControl(){
	return control;
}

void ofxUCVQTKitVideoGrabber::onAutoExposureChange(bool & enable){
	control.setAutoExposure(enable);
}
void ofxUCVQTKitVideoGrabber::onExposureChange(float & value){
	control.setExposure(value);
}

void ofxUCVQTKitVideoGrabber::onAutoFocusChange(bool & enable){
	control.setAutoFocus(enable);
}
void ofxUCVQTKitVideoGrabber::onAbsoluteFocusChange(float & value){
	control.setAbsoluteFocus(value);
}

void ofxUCVQTKitVideoGrabber::onAutoWhiteBalanceChange(bool & enable){
	control.setAutoWhiteBalance(enable);
}
void ofxUCVQTKitVideoGrabber::onWhiteBalanceChange(float & value){
	control.setWhiteBalance(value);
}

void ofxUCVQTKitVideoGrabber::onGainChange(float & value){
	control.setGain(value);
}
void ofxUCVQTKitVideoGrabber::onBrightnessChange(float & value){
	control.setBrightness(value);
}
void ofxUCVQTKitVideoGrabber::onContrastChange(float & value){
	control.setContrast(value);
}
void ofxUCVQTKitVideoGrabber::onSaturationChange(float & value){
	control.setSaturation(value);
}
void ofxUCVQTKitVideoGrabber::onSharpnessChange(float & value){
	control.setSharpness(value);
}