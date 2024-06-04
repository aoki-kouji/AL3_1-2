#include <Skydome.h>

void Skydome::Initialize(Model* model, ViewProjection* viewProjection) { 
	model_ = model;
	viewProjection_ = viewProjection;
	worldTransform_. Initialize();
}

void Skydome::Update(){}

void Skydome::Draw() { 
	model_->Draw(worldTransform_, *viewProjection_);
}