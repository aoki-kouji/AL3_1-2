#include"Enemy.h"
#include"myMath.h"
#include<cassert>
#include<numbers>

void Enemy::Initialize(Model* model, const Vector3& position, ViewProjection* viewProjection) {

	worldTransform_.Initialize();
	model_ = model;
	worldTransform_.translation_ = position;
	viewProjection_ = viewProjection;
	model_ = Model::CreateFromOBJ("enemy", true);

	velocity_ = {
	    -kWalkspeed,
	    0,
	    0,
	};

	walkTimer_ = 0.0f;

	worldTransform_.rotation_.y = std::numbers::pi_v<float> * 3.0f / 2.0f;
}

void Enemy::Update() {
	// 敵の移動
	worldTransform_.translation_.x += velocity_.x;

	worldTransform_.UpdateMatrix();

	walkTimer_ += 1.0f / 60.0f;

	worldTransform_.rotation_.x =
	    std::sin(std::numbers::pi_v<float> * 2.0f * walkTimer_ / kWalkMotionTime);
}

void Enemy::Draw() {
	// 3Dモデル描画
	model_->Draw(worldTransform_, *viewProjection_);
}