#pragma once

#include "ofMain.h"
#include "of3dGraphics.h"
#include "bird.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// ŒÂ‘Ì‚ÌŒQ‚ê‚ğ4‚ÂéŒ¾
		vector<bird>birds1;
		vector<bird>birds2;
		vector<bird>birds3;
		vector<bird>birds4;
		vector<bird>nullBirds;
		
		bool active; //“®‚«‚Ì§Œä
};
