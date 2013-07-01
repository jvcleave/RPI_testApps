#include "ofMain.h"
#include "testApp.h"
#ifdef TARGET_OPENGLES
	#ifdef PROGRAMMABLE_PRESENT
		#include "ofGLProgrammableRenderer.h"
	#else
		#include "ofGLES2Renderer.h"
	#endif
#endif
//========================================================================
int main( ){
	ofSetLogLevel(OF_LOG_VERBOSE); 
	#ifdef TARGET_OPENGLES
		#ifdef PROGRAMMABLE_PRESENT
			ofSetCurrentRenderer(ofPtr<ofBaseRenderer>(new ofGLProgrammableRenderer()));
		#else
			ofSetCurrentRenderer(ofPtr<ofBaseRenderer>(new ofGLES2Renderer()));
		#endif
	#endif
	ofSetupOpenGL(1280,720, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
