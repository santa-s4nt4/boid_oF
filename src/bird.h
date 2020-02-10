#pragma once
#include "ofMain.h"

class bird {
public:
	bird(vector<bird>* const, const int, ofColor, vector<bird>* const, vector<bird>* const, vector<bird>* const);
	virtual ~bird();

	virtual void update();
	virtual void draw();

	int id; // �Q��̒��̌̂̎��ʔԍ�
	float head; // �̂̓��̔��a
	float tail; // �̂̔��̒���
	ofVec2f pos; // �̂̈ʒu
	ofVec2f vel; // �̂̑��x
	ofVec2f acc; // �̂̉����x
	ofColor ourColor; // �̂̐F

protected:
	vector<bird>* pSelfGroup; // �����̏�������Q��
	vector<bird>* pEnemyGroup; // �G�΂���Q��
	vector<bird>* pFriendGroup; // �F�D�I�ȌQ��
	vector<bird>* pFriendGroup2; // �F�D�I�ȌQ��2

	ofVec2f separationVel; // ����
	ofVec2f alignmentVel; // ����
	ofVec2f cohesionVel; // ����
	ofVec2f groupCenterPos; // �Q��̒��S�ʒu
};