#include "Player.h"
#include <cassert>


void Player::Initialize(Model* model, uint32_t textureHandle) {

// NULL�`�F�b�N
	assert(model);
    worldTransform_.Initialize();
	// �����̓��e�������o�ϐ��ɋL�^
	model_ = model;
	textureHandle_ = textureHandle;


}
void Player::update() {}

void Player::Draw() {}
