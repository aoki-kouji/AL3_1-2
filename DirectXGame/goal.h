#include <AABB.h>
#include <Input.h>
#include <myMath.h>
#include <Model.h>
#include <Vector3.h>
#include <WorldTransform.h>
#include <algorithm>
#include <numbers>
#include <cassert>


class MapChipField;
class Player;

class Goal {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// デスフラグのgetter
	bool IsFinished() const { return finished_; }

	void SetMapChipField(MapChipField* mapChipField) { mapChipField_ = mapChipField; }

	Vector3 GetworldPosition();

	AABB GetAABB();

	// 衝突応答
	void OnCollision(const Player* player);

private:
	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// 3Dモデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	ViewProjection* viewProjection_ = nullptr;

	// マップチップによるフィールド
	MapChipField* mapChipField_ = nullptr;

	// 終了フラグ
	bool isFinished_ = false;
	// 終了フラグ
	bool finished_ = false;

	static inline const float kWidth = 0.8f;
	static inline const float kHeight = 0.8f;
};