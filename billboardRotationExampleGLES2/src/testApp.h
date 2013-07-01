#pragma once
#include "ofMain.h"
#include "ofVbo.h"
#include "FPSLogger.h"

#define NUM_BILLBOARDS 500


class testApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
	
		void keyPressed(int key);

		ofVbo vbo;
		ofShader shader;
		ofImage texture;

		vector<ofVec3f> pos;
		ofVboMesh mesh;
		
		ofVec2f vel[NUM_BILLBOARDS];
		ofVec2f home[NUM_BILLBOARDS];
		float pointSizes[NUM_BILLBOARDS];
		float rotations[NUM_BILLBOARDS];
	ofVec2f mouse;
	ofVec2f mouseVec;
	
	int fakeMouseX;
	int fakeMouseY;
	int fakePreviousMouseX;
	int fakePreviousMouseY;
	
	FPSLogger fpsLogger;
};









