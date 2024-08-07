#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <array>
#include <numbers>

class DeathParticles {
public:
	void Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position);

	void Update();

	void Draw();

	bool IsFinished() const { return isFinished_; };

private:
	static inline const uint32_t kNumParticles = 8;
	static inline const float kDuration = 2.0f;
	static inline const float kSpeed = 0.05f;
	static inline const float kAngleUnit = 2.0f * std::numbers::pi_v<float> / kNumParticles;

	Model* model_ = nullptr;
	std::array<WorldTransform, kNumParticles> worldTransforms_;
	ViewProjection* viewProjection_ = nullptr;
	bool isFinished_ = false;
	float counter_ = 0.0f;
	
};