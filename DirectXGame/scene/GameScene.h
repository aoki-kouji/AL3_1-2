#pragma once

#include <vector>

#include "Audio.h"
#include "CameraController.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "MapChipField.h"
#include "Model.h"
#include "Player.h"
#include "Skydome.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"Enemy.h"
#include"DeathParticles.h"
#include<list>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	enum class Phase {
		kPlay,  // ゲームプレイ
		kDeath, // デス演出
	};

	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	// ビュープロジェクション
	ViewProjection viewProjection_;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// 自キャラ
	Player* player_ = nullptr;
	Enemy* enemy_ = nullptr;
	// モデルデータ
	Model* modelPlayer_ = nullptr;
	Model* modelBlock_ = nullptr;
	Model* modelSkydome_ = nullptr;
	Model* modelEnemy_ = nullptr;
	Model* modelDeathParticle_ = nullptr;
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;
	WorldTransform worldTransformSkydome_;
	// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;
	// デバッグカメラ有効
	bool isDebugCameraActive_ = false;
	// マップチップフィールド
	MapChipField* mapChipField_;
	CameraController* cameraController = nullptr;

	std::list<Enemy*> enemies_;
	Enemy* newEnemy_ = nullptr;

	Phase phase_;

	DeathParticles* deathParticles_ = nullptr;

	void ChangePhase();

	void GenerateBlocks();

	void UpdateCamera();

	void UpdateBlocks();

	// 衝突判定と応答

	void CheckAllCollisions();
};