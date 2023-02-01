// 3D Box example from the openFrameworks repo
//   github.com/openframeworks/openFrameworks


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// std::cout << "OF data path is " << ofFilePath::getAbsolutePath(ofToDataPath("")) << std::endl;

    // The 'data' path by default differs on mac vs other platforms.
    // For Chalet, We set it to simply 'data' to assert the location is always relative to the executable
    // so that when the app is run through Chalet, it can find data, and also when the project is bundled
    // on MacOS, data can be placed in Resources
    //
	ofSetDataPathRoot("data/");

	ofSetVerticalSync(true);

	// this uses depth information for occlusion
	// rather than always drawing things on top of each other
	ofEnableDepthTest();

	// ofBox uses texture coordinates from 0-1, so you can load whatever
	// sized images you want and still use them to texture your box
	// but we have to explicitly normalize our tex coords here
	ofEnableNormalizedTexCoords();

	// loads the OF logo from disk
	ofLogo.load("of.png");

	// draw the ofBox outlines with some weight
	ofSetLineWidth(10);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);

	float movementSpeed = .1;
	float cloudSize = ofGetWidth() / 2;
	float maxBoxSize = 100;
	float spacing = 1;
	int boxCount = 100;

	cam.begin();

	for(int i = 0; i < boxCount; i++) {
		ofPushMatrix();

		float t = (ofGetElapsedTimef() + i * spacing) * movementSpeed;
		glm::vec3 pos(
			ofSignedNoise(t, 0, 0),
			ofSignedNoise(0, t, 0),
			ofSignedNoise(0, 0, t));

		float boxSize = maxBoxSize * ofNoise(pos.x, pos.y, pos.z);

		pos *= cloudSize;
		ofTranslate(pos);
		ofRotateXDeg(pos.x);
		ofRotateYDeg(pos.y);
		ofRotateZDeg(pos.z);

		ofLogo.bind();
		ofFill();
		ofSetColor(255);
		ofDrawBox(boxSize);
		ofLogo.unbind();

		ofNoFill();
		ofSetColor(ofColor::fromHsb(sinf(t) * 128 + 128, 255, 255));
		ofDrawBox(boxSize * 1.1f);

		ofPopMatrix();
	}

	cam.end();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
