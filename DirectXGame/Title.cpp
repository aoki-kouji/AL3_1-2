#define NOMINMAX
#include"Title.h"
#include"DirectXCommon.h"
#include"Input.h"
#include<cmath>
#include<numbers>

TitleScene::~TitleScene() {
	delete modelPlayer_;
}

void TitleScene::Initialize() {
	modelPlayer_ = Model::CreateFromOBJ("player");
	// ビュープロジェクションの初期化
	viewProjection_.Initialize();

	const float kPlayerScale = 10.0f;
	worldTransformPlayer_.Initialize();
	worldTransformPlayer_.scale_ = {kPlayerScale, kPlayerScale, kPlayerScale};
	worldTransformPlayer_.rotation_.y = 0.95f * std::numbers::pi_v<float>;
	worldTransformPlayer_.translation_.y = -9.0f;

	const float kTextTitle = 10.0f;
	worldTransformTitle_.Initialize();
	worldTransformTitle_.scale_ = {kTextTitle, kTextTitle, kTextTitle};
	worldTransformTitle_.rotation_.y = 0.99f * std::numbers::pi_v<float>;
}

void TitleScene::Update() {
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		finished_ = true;
	}
	counter_ += 1.0f / 60.0f;
	counter_ = std::fmod(counter_, kTimeTitleMove);

	float angle = counter_ / kTimeTitleMove * 2.0f * std::numbers::pi_v<float>;

	worldTransformTitle_.translation_.y = std::sin(angle) + 10.0f;

	viewProjection_.TransferMatrix();
	
	worldTransformPlayer_.UpdateMatrix();
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon_ = DirectXCommon::GetInstance();
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);
	modelPlayer_->Draw(worldTransformPlayer_, viewProjection_);
	Model::PostDraw();
}