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

	for (int i = 0; i < pSelfGroup->size(); i++) { // 自分自身の群れ内での相互作用
		bird& rAnother = pSelfGroup->at(i);
		if (rAnother.id != id) { // 自分自身との相互作用は除く
			float dist = pos.distance(rAnother.pos);
			if (dist < 10) { // 分離
				separationVel += pos - rAnother.pos;
				separationCount++;
			}
			else if (dist < 35) { // 整列
				alignmentVel += rAnother.vel.getNormalized();
				alignmentCount++;
			}
			else if (dist < 60) { // 結合
				groupCenterPos += rAnother.pos;
				cohesionCount++;
			}
		}
	}

	for (int i = 0; i < pFriendGroup->size(); i++) { // 友好的な群れとの相互作用
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

	for (int i = 0; i < pFriendGroup2->size(); i++) { // 友好的な群れとの相互作用
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

	for (int i = 0; i < pEnemyGroup->size(); i++) { // 敵対的な群れとの相互作用
		bird& rAnother = pEnemyGroup->at(i);
		float dist = pos.distance(rAnother.pos);
		if (dist < 60) {
			separationVel += pos - rAnother.pos;
			separationCount++;
		}
	}

	// 速度ベクトルの正規化(大きさを1にする)
	separationVel /= separationCount;
	separationVel.getNormalized();
	alignmentVel /= alignmentCount;
	alignmentVel.getNormalized();

	groupCenterPos /= cohesionCount;
	cohesionVel = groupCenterPos - pos;
	cohesionVel.normalize();

	// 分離，整列，結合の速度を重み付けをして速度に足し込む
	vel += (separationVel*0.15) + (alignmentVel*0.035) + (cohesionVel*0.02);
	vel.scale(1.5);
	pos += vel;

	// 買え際処理 : 壁にぶつかると反射する(速度の符号反転)
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
	// 個体の描画
	ofSetColor(ourColor);
	ofDrawCircle(pos, head);
	ofLine(pos.x + vel.x*tail*0.5, pos.y + vel.y*tail*0.5, pos.x - vel.x*tail, pos.y - vel.y*tail);
}