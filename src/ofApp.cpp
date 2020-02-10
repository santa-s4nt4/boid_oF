#include "ofApp.h"

// 4つの群れの個体数
#define BOID1 100
#define BOID2 80
#define BOID3 120
#define BOID4 50

#define BGCOLOR ofColor(0,0,0,32) // 背景色
#define COLOR1 ofColor(255,0,0,255) // 群れの個体の色
#define COLOR2 ofColor(0,255,0,255)
#define COLOR3 ofColor(0,255,255,255)
#define COLOR4 ofColor(255,255,0,255)

#define FRATE 60 // フレームレート

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(FRATE);
	ofEnableAlphaBlending();
	ofSetBackgroundColor(0);
	ofSetBackgroundAuto(false);
	ofSetCircleResolution(64);
	ofHideCursor();
	ofSetBackgroundColor(BGCOLOR);
	active = true;

	// self, enemy, friend1, friend2 群れの生成
	birds1.reserve(BOID1);
	for (int i = 0; i < BOID1; i++) {
		birds1.push_back(*new bird(&birds1, i, COLOR1, &birds2, &birds3, &nullBirds));
	}
	birds2.reserve(BOID2);
	for (int i = 0; i < BOID2; i++) {
		birds2.push_back(*new bird(&birds2, i, COLOR2, &nullBirds, &birds3, &nullBirds));
	}
	birds3.reserve(BOID3);
	for (int i = 0; i < BOID3; i++) {
		birds3.push_back(*new bird(&nullBirds, i, COLOR3, &nullBirds, &birds2, &nullBirds));
	}
	birds4.reserve(BOID4);
	for (int i = 0; i < BOID4; i++) {
		birds4.push_back(*new bird(&birds4, i, COLOR4, &birds1, &birds3, &nullBirds));
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if (active) { //activeのがtrueのとき、群れの更新
		for (int i = 0; i < birds1.size(); i++) {
			birds1[i].update();
		}
		for (int i = 0; i < birds2.size(); i++) {
			birds2[i].update();
		}
		for (int i = 0; i < birds3.size(); i++) {
			birds3[i].update();
		}
		for (int i = 0; i < birds4.size(); i++) {
			birds4[i].update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(BGCOLOR);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	for (int i = 0; i < birds1.size(); i++) {
		birds1[i].draw();
	}
	for (int i = 0; i < birds2.size(); i++) {
		birds2[i].draw();
	}
	for (int i = 0; i < birds3.size(); i++) {
		birds3[i].draw();
	}
	for (int i = 0; i < birds4.size(); i++) {
		birds4[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case ' ':
		active = !active;
		break;
	case 'f':
		ofToggleFullscreen(); //フルスクリーン切り替え
		break;
	case 's':
		ofShowCursor(); //カーソル表示
		break;
	case 'h':
		ofHideCursor(); //カーソル非表示
		break;
	default:
		break;
	}
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
