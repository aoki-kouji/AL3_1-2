#include "Player.h"
#include <cassert>


void Player::Initialize(Model* model, uint32_t textureHandle) {

// NULLチェック
	assert(model);
    worldTransform_.Initialize();
	// 引数の内容をメンバ変数に記録
	model_ = model;
	textureHandle_ = textureHandle;


}
void Player::update() {}

void Player::Draw() {}
