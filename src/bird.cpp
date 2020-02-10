#include "bird.h"

bird::bird(vector<bird>* const _pSelfGroup, const int _id, const ofColor _ourColor, vector<bird>* const _pEnemyGroup, vector<bird>* const _pFriendGroup, vector<bird>* const _pFriendGroup2) {
	pSelfGroup = _pSelfGroup;
	pEnemyGroup = _pEnemyGroup;
	pFriendGroup = _pFriendGroup;
	pFriendGroup2 = _pFriendGroup2;
	id = _id;
	ourColor = _ourColor;
	pos.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
	vel.set(ofRandom(-2, 2), ofRandom(-2, 2));
	head = 2;
	tail = head * 2;
}

bird::~bird() {

}

void bird::update() {
	int separationCount = 0;
	int alignmentCount = 0;
	int cohesionCount = 0;
	separationVel.set(0, 0);
	alignmentVel.set(0, 0);
	cohesionVel.set(0, 0);
	groupCenterPos.set(0, 0);

	for (int i = 0; i < pSelfGroup->size(); i++) { // �������g�̌Q����ł̑��ݍ�p
		bird& rAnother = pSelfGroup->at(i);
		if (rAnother.id != id) { // �������g�Ƃ̑��ݍ�p�͏���
			float dist = pos.distance(rAnother.pos);
			if (dist < 10) { // ����
				separationVel += pos - rAnother.pos;
				separationCount++;
			}
			else if (dist < 35) { // ����
				alignmentVel += rAnother.vel.getNormalized();
				alignmentCount++;
			}
			else if (dist < 60) { // ����
				groupCenterPos += rAnother.pos;
				cohesionCount++;
			}
		}
	}

	for (int i = 0; i < pFriendGroup->size(); i++) { // �F�D�I�ȌQ��Ƃ̑��ݍ�p
		bird& rAnother = pFriendGroup->at(i);
		float dist = pos.distance(rAnother.pos);
		if (dist < 10) {
			separationVel += pos - rAnother.pos;
			separationCount++;
		}
		else if (dist < 35) {
			alignmentVel += rAnother.vel.getNormalized();
			alignmentCount++;
		}
		else if (dist < 60) {
			groupCenterPos += rAnother.pos;
			cohesionCount++;
		}
	}

	for (int i = 0; i < pFriendGroup2->size(); i++) { // �F�D�I�ȌQ��Ƃ̑��ݍ�p
		bird& rAnother = pFriendGroup2->at(i);
		float dist = pos.distance(rAnother.pos);
		if (dist < 10) {
			separationVel += pos - rAnother.pos;
			separationCount++;
		}
		else if (dist < 35) {
			alignmentVel += rAnother.vel.getNormalized();
			alignmentCount++;
		}
		else if (dist < 60) {
			groupCenterPos += rAnother.pos;
			cohesionCount++;
		}
	}

	for (int i = 0; i < pEnemyGroup->size(); i++) { // �G�ΓI�ȌQ��Ƃ̑��ݍ�p
		bird& rAnother = pEnemyGroup->at(i);
		float dist = pos.distance(rAnother.pos);
		if (dist < 60) {
			separationVel += pos - rAnother.pos;
			separationCount++;
		}
	}

	// ���x�x�N�g���̐��K��(�傫����1�ɂ���)
	separationVel /= separationCount;
	separationVel.getNormalized();
	alignmentVel /= alignmentCount;
	alignmentVel.getNormalized();

	groupCenterPos /= cohesionCount;
	cohesionVel = groupCenterPos - pos;
	cohesionVel.normalize();

	// �����C����C�����̑��x���d�ݕt�������đ��x�ɑ�������
	vel += (separationVel*0.15) + (alignmentVel*0.035) + (cohesionVel*0.02);
	vel.scale(1.5);
	pos += vel;

	// �����ۏ��� : �ǂɂԂ���Ɣ��˂���(���x�̕������])
	if (pos.x < 0) {
		vel.x *= -1;
	}
	else if (pos.x >= ofGetWidth()) {
		vel.x *= -1;
	}
	else if (pos.y < 0) {
		vel.y *= -1;
	}
	else if (pos.y >= ofGetHeight()) {
		vel.y *= -1;
	}
}

void bird::draw() {
	// �̂̕`��
	ofSetColor(ourColor);
	ofDrawCircle(pos, head);
	ofLine(pos.x + vel.x*tail*0.5, pos.y + vel.y*tail*0.5, pos.x - vel.x*tail, pos.y - vel.y*tail);
}