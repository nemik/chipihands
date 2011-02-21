#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	context.setupUsingXMLFile();
	depth.setup(&context);
	image.setup(&context);
	user.setup(&context, &depth);
	
	hands.loadImage("chipihands.jpg");
	head.loadImage("sun.jpg");
	hands.resize(80, 110);
	head.resize(100, 100);
	ofSetColor(255, 255, 255);
}

//--------------------------------------------------------------
void testApp::update()
{
	context.update();
	user.update();
	ofxOpenNIContext * ccontext = &context;
	//ccontext->getXnContext().EnumerateLicenses(liceses, count);
}

//--------------------------------------------------------------
void testApp::draw()
{
	//depth.draw(0,0,320,240);
	//user.draw();
	image.draw(0, 0, 640, 480);
	
	ofxTrackedUser* tracked = user.getTrackedUser(0);
	if(tracked != NULL) 
	{
		tracked->debugDraw();
		
		int xl = tracked->left_lower_arm.end.x;
		int yl = tracked->left_lower_arm.end.y;
		
		int xr = tracked->right_lower_arm.end.x;
		int yr = tracked->right_lower_arm.end.y;
		
		int xh = tracked->neck.begin.x;
		int yh = tracked->neck.begin.y;
		
		ofSetColor(255, 255, 255);
		hands.draw(xl, yl);
		hands.draw(xr, yr);
		
		head.draw(xh, yh);
		
		XnUSBDeviceSpeed* pDevSpeed;
		xnUSBGetDeviceSpeed(usbhandle, pDevSpeed);
		
		char rstr[1024];
		sprintf(rstr, "DEV SPEED: %d", (int)pDevSpeed);
		ofDrawBitmapString(rstr, 400,400);		
		xnUSBCloseDevice(usbhandle);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

