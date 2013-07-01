#include "ofMain.h"
#include "testApp.h"

#ifdef GLES2_PRESENT
	#warning "!!!!!!! GLES2 PRESENT !!!!!!!!"
#else
	#warning "!!!!!!! GLES2 ABSENT !!!!!!!!"
#endif

#ifdef PROGRAMMABLE_PRESENT
	#warning "!!!!!!! PROGRAMMABLE PRESENT !!!!!!!!"
#else
	#warning "!!!!!!! PROGRAMMABLE ABSENT !!!!!!!!"
#endif


#ifdef TARGET_OPENGLES
#include "ofGLProgrammableRenderer.h"
#endif
//========================================================================
int main( ){

	ofSetLogLevel(OF_LOG_VERBOSE);
	#ifdef TARGET_OPENGLES
	ofSetCurrentRenderer(ofPtr<ofBaseRenderer>(new ofGLProgrammableRenderer()));
	#endif
	ofSetupOpenGL(1280,720, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
