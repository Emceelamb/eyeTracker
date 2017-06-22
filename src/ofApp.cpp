#include "ofApp.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

using namespace ofxCv;
using namespace cv;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(120);

	camWidth = 1280;
	camHeight = 720;

	//objectFinder.setup(ofToDataPath("C:/Users/blargh/Documents/Processing/libraries/opencv_processing/library/cascade-files/haarcascade_eye.xml"));

	//objectFinder.setup(ofToDataPath("C:/Users/blargh/Documents/Processing/libraries/opencv_processing/library/cascade-files/haarcascade_mcs_mouth.xml"));

	//objectFinder.setup(ofToDataPath("haarcascade_eye_tree_eyeglasses.xml"));
	objectFinder.setup(ofToDataPath("haarcascade_eye.xml"));
	objectFinder.setPreset(ObjectFinder::Fast);	
	cam.setup(1280, 720);
	cropped.allocate(200, 200, OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
	cam.update();
	if (cam.isFrameNew()) {
		objectFinder.update(cam);
		if (objectFinder.size() > 0) {
			cv::Rect roi = toCv(objectFinder.getObject(0));
			Mat camMat = toCv(cam);
			Mat croppedCamMat(camMat, roi);
			resize(croppedCamMat, cropped);
			cropped.update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//cam.draw(0, 0);
	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 9; ++y) {
			cropped.draw(200*x, 200*y);
		}
		
	}
	//cropped.draw(camWidth, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
