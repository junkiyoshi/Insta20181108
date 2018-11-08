#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);

	for (int i = 1; i <= 4; i++) {
	
		ofImage image;
		image.loadImage("images/cat" + std::to_string(i) + ".png");
		this->cat_images.push_back(image);
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int x = 5; x < ofGetWidth(); x += 144) {

		for (int y = -36; y <= ofGetHeight(); y += 144) {

			int index = ofNoise(x * 0.01, y * 0.01, ofGetFrameNum() * 0.005) * this->cat_images.size();
			this->cat_images[index].draw(x, y - this->cat_images[index].getHeight());
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}