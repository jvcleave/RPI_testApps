#pragma once

#include "ofMain.h"

#include "FPSLogger.h"

class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		void exit();
	
		void keyPressed(int key);	
		
	ofImage tex0Source;
	ofImage tex1Source;
	
	ofTexture tex0;
	ofTexture tex1;
	
	float drawWidth;
	float drawHeight;
	
	ofShader shader;
	ofFbo fbo;

	FPSLogger fpsLogger;
};

