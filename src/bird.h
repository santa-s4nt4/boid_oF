#pragma once
#include "ofMain.h"

class bird {
public:
	bird(vector<bird>* const, const int, ofColor, vector<bird>* const, vector<bird>* const, vector<bird>* const);
	virtual ~bird();

	virtual void update();
	virtual void draw();

	int id; // ŒQ‚ê‚Ì’†‚ÌŒÂ‘Ì‚Ì¯•Ê”Ô†
	float head; // ŒÂ‘Ì‚Ì“ª‚Ì”¼Œa
	float tail; // ŒÂ‘Ì‚Ì”ö‚Ì’·‚³
	ofVec2f pos; // ŒÂ‘Ì‚ÌˆÊ’u
	ofVec2f vel; // ŒÂ‘Ì‚Ì‘¬“x
	ofVec2f acc; // ŒÂ‘Ì‚Ì‰Á‘¬“x
	ofColor ourColor; // ŒÂ‘Ì‚ÌF

protected:
	vector<bird>* pSelfGroup; // ©•ª‚ÌŠ‘®‚·‚éŒQ‚ê
	vector<bird>* pEnemyGroup; // “G‘Î‚·‚éŒQ‚ê
	vector<bird>* pFriendGroup; // —FD“I‚ÈŒQ‚ê
	vector<bird>* pFriendGroup2; // —FD“I‚ÈŒQ‚ê2

	ofVec2f separationVel; // •ª—£
	ofVec2f alignmentVel; // ®—ñ
	ofVec2f cohesionVel; // Œ‹‡
	ofVec2f groupCenterPos; // ŒQ‚ê‚Ì’†SˆÊ’u
};