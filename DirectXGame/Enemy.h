#pragma once
#include"Model.h"
#include"ViewProjection.h"
#include"WorldTransform.h"

class Enemy {

public:
	/// 初期化

	void Initialize(Model* model, const Vector3& position, ViewProjection* viewProjection);
	void Initialize(const Vector3& position, ViewProjection* viewProjection);

	/// 更新
	void Update();

	/// 描画

	void Draw();

private:
	/// 最初の角度

	static inline const float kAcceleration = 0.01f;

	// 最後の角度
	// static inline const float kWalkMotionAngleEnd = 35.0f;
	// ワールド変換データ
	WorldTransform worldTransform_;
	ViewProjection* viewProjection_ = nullptr;
	// モデル
	Model* model_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	static inline const float kWalkspeed = 0.02f;

	Vector3 velocity_ = {};

	// 最初の角度
	static inline const float kWalkMotionAngleStart = 0.5;

	// 最後の角度
	static inline const float kWalkMotionAngleEng = 1;

	// アニメーションの時間
	static inline const float kWalkMotionTime = 2;

	// 経過時間
	float walkTimer_ = 0.0f;
};