#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofBackground(0);
	// billboard particles
	for (int i=0; i<NUM_BILLBOARDS; i++) {
		pos.push_back(ofVec3f(ofRandomWidth(), ofRandomHeight(), 0));
		vel[i].x = ofRandomf();
		vel[i].y = ofRandomf();
		home[i] = pos[i];
		pointSizes[i] = ofNextPow2(ofRandom(2, 40));
		rotations[i] = ofRandom(0, 360);
	}
	
	shader.load("BillboardGLES2");
	mesh.setUsage(GL_DYNAMIC_DRAW);
	// set the vertex data
	mesh.addVertices(pos);
	
	texture.loadImage("snow.png");
	fakeMouseX = ofGetWidth()/2;
	fakeMouseY = ofGetHeight()/2;
	fakePreviousMouseX = 0;
	fakePreviousMouseY = 0;
}

//--------------------------------------------------------------
void testApp::update() {
	
	fakePreviousMouseX = fakeMouseX;
	fakePreviousMouseY = fakeMouseY;
	if (fakeMouseX<ofGetWidth()) 
	{
		fakeMouseX++;
	}else 
	{
		fakeMouseX = 0;
	}
	if (fakeMouseY<ofGetHeight()) 
	{
		fakeMouseY++;
	}else 
	{
		fakeMouseY = 0;
	}
	
	mouse.set(fakeMouseX, fakeMouseY);
	mouseVec.set(fakePreviousMouseX-fakeMouseX, fakePreviousMouseY-fakeMouseY);
	
	mouseVec.limit(10.0);
	
	for (int i=0; i<NUM_BILLBOARDS; i++) 
	{
		ofSeedRandom(i);
		ofVec3f &point = mesh.getVertices()[i];
		
		
		if(mouse.distance(point) < ofRandom(100, 200)) 
		{
			vel[i] -= mouseVec; 
		}
		
		point += vel[i];
		vel[i] *= 0.84f;
		
		if(point.x < 0) point.x = ofGetWidth();
		if(point.x > ofGetWidth()) point.x = 0;
		if(point.y < 0) point.y = ofGetHeight();
		if(point.y > ofGetHeight()) point.y = 0;
		
		ofVec2f center(ofGetWidth()/2, ofGetHeight()/2);
		ofVec2f frc = home[i] - point;
		if(frc.length() > 20.0) {
			frc.normalize();
			frc *= 0.84;
			vel[i] += frc;
		}
		
		// get the 2d heading
		float angle = (float)atan2(-vel[i].y, vel[i].x) + PI;
		rotations[i] = (angle * -1.0);
	}
}

//--------------------------------------------------------------
void testApp::draw() {
	ofEnableAlphaBlending();
	ofSetColor(255);
	
	shader.begin();
	
	// we are getting the location of the point size attribute
	// we then set the pointSizes to the vertex attritbute
	// we then bind and then enable
	int pointAttLoc = shader.getAttributeLocation("pointSize");
	glVertexAttribPointer(pointAttLoc, 1, GL_FLOAT, false, 0, pointSizes);
	glBindAttribLocation(shader.getProgram(), pointAttLoc, "pointSize");
	glEnableVertexAttribArray(pointAttLoc);
	
	// rotate the snow based on the velocity
	int angleLoc = shader.getAttributeLocation("angle");
	glVertexAttribPointer(angleLoc, 1, GL_FLOAT, false, 0, rotations);
	glBindAttribLocation(shader.getProgram(), angleLoc, "angle");
	glEnableVertexAttribArray(angleLoc);
	
	texture.getTextureReference().bind();
	
	mesh.drawVertices();
	
	
	texture.getTextureReference().unbind();
	
	shader.end();
	
	// disable vertex attributes
	glDisableVertexAttribArray(pointAttLoc); 
	glDisableVertexAttribArray(angleLoc);
	ofPushMatrix();
		ofPushStyle();
			ofSetColor(ofColor::green, 128);
			ofCircle(fakeMouseX, fakeMouseY, 200);
			ofDrawBitmapStringHighlight(ofGetCurrentRenderer()->getType()+"\nFPS: " + ofToString(ofGetFrameRate()), 100, 100,  ofColor::black, ofColor::yellow);

		ofPopStyle();
	ofPopMatrix();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}
