#ofxUVCQTKitVideoGrabber

Openframeworks addon that simplifies the usage of [ofxQTKitVideoGrabber](https://github.com/Flightphase/ofxQTKitVideoGrabber) in conjunction with [ofxUVC](https://github.com/atduskgreg/ofxUVC).

##Usage
ofxUVCQTKitVideoGrabber extends ofxQTKitVideoGrabber so you can do everything you would normally do with it. On top of that it includes a ofxUVC control member and an (optional) GUI.
##### testApp.h

    #include "ofxUVCQTKitVideoGrabber.h"

    class testApp : public ofBaseApp{
	    public:
		    (...)
	    	ofxUVCQTKitVideoGrabber cam;
    };

##### testApp.cpp

	// example for Logitech's c910 camera
    void testApp::setup(){
		cam.initGrabber(1280, 720);
		cam.setupControls(ofxUVCQTKitVideoGrabber::LOGITECH_C910);
		cam.setupGui("Camera Settings", "settings.xml");
    }
    void testApp::update(){
    	cam.update();
    }
    void testApp::draw(){
    	cam.draw(0,0);
    	cam.drawGui();
    }
##Supported Cameras
You can use the UVC controls for any camera you know the **vendor id**, **product id** and **interface number**. Google for the "USB Prober" app as it will help you find those.

With these in hand, you can setup the controls using the overloaded ``setupControls`` method:

	cam.setupControls(vendorId, productId, interfaceNum);
	
The but the addon also comes with a list of tested cameras (please contribute if you know more!), that, at the time of this writting is:

	MICROSOFT_LIFECAM_HD_5000,
	MICROSOFT_LIFECAM_HD_3000,
	ENCORE_ELECTRONICS_ENUCM_013,
	ROSEWILL,
	BUILT_IN_ISIGHT,
	LOGITECH_C910,
	LOGITECH_C6260

With those you can easily setup the controls:

	cam.setupControls(ofxUVCQTKitVideoGrabber::LOGITECH_C910);
	
##License
You can do whatever you want with this code (and I don't take any reponsabillity for it). But I suggest you checking the individual licenses for [ofxQTKitVideoGrabber](https://github.com/Flightphase/ofxQTKitVideoGrabber) and [ofxUVC](https://github.com/atduskgreg/ofxUVC). 