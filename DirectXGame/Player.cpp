#include "Player.h"
#include <cassert>

void Player::Initialize(Model* model, uint32_t textureHandle,ViewProjection* viewProjection) {

	// NULLチェック
	assert(model);
	worldTransform_.Initialize();
	// 引数の内容をメンバ変数に記録
	model_ = model;
	textureHandle_ = textureHandle;
	viewProjection_ = viewProjection;
}
void Player::Update() {

    worldTransform_.TransferMatrix();

}

void Player::Draw() {

model_->Draw(worldTransform_, *viewProjection_, textureHandle_);

}
