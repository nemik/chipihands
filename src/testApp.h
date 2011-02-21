#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxOpenNI.h"
#include <XnOpenNI.h>
#include <XnUSB.h>

class testApp : public ofBaseApp
{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		ofxOpenNIContext context;
		ofxDepthGenerator depth;
		ofxImageGenerator image;
		ofxUserGenerator user;
		
		ofImage hands;
		ofImage head;
	
		XN_USB_DEV_HANDLE usbhandle;
};

#endif
