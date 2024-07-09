#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

/// <summary>
/// 自キャラ
/// </summary>
class Player {
public:
	// 左右
	enum class LRDirection {
		kRight,
		kLeft,
	};

	/// <summary>
	/// 初期化
	/// </summary>
	//	void Initialize(Model* model, uint32_t textureHandle, ViewProjection* viewProjection);
	void Initialize(Model* model, const Vector3& position, ViewProjection* viewProjection);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	//Player* player = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewProjection_ = nullptr;

	Vector3 velocity_ = {};

	static inline const float kAcceleration = 0.01f;
	static inline const float kAttenuation = 0.01f;
	static inline const float kLimitRunSpeed = 2.0f;

	LRDirection lrDirection_ = LRDirection::kRight;

	// 旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	// 旋回タイマー
	float turnTimer_ = 0.0f;

	// 旋回時間<秒>
	static inline const float kTimeTurn = 0.3f;

	// 接地状態フラグ
	bool onGround_ = true;
	// 着地フラグ
	bool landing = false;

	// 重力加速度（下方向）
	static inline const float kGravityAcceleration = 0.05f;
	// 最大落下速度（下方向）
	static inline const float kLimitFallSpeed = 0.2f;
	// ジャンプ初速（上方向）
	static inline const float kJumpAcceleration = 0.7f;
};










//#include "WorldTransform.h"
//#include "ViewProjection.h"
//#include "Model.h"
/////自キャラ
//
//class Player{
//public:
//    //初期化
//	void Initialize(Model* model,uint32_t textureHandle,ViewProjection* viewProjection);
//	//更新
//	void Update();
//	//描画
//	void Draw();
//
//private:
//    //ワールド変換
//	WorldTransform worldTransform_;
//	//モデル
//	Model* model_ = nullptr;
//	//テクスチャハンドル
//	uint32_t textureHandle_ = 0u;
//
//	ViewProjection* viewProjection_ = nullptr;
//};