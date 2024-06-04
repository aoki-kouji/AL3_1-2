#include<Model.h>
#include<WorldTransform.h>
#include<ViewProjection.h>
//天球
class Skydome{

public:

//初期化
	void Initialize(Model* model, ViewProjection* viewProjection);
//更新
	void Update();
//描画
	void Draw();

private:
//ワールド変換データ
WorldTransform worldTransform_;
//モデル
Model* model_ = nullptr;
//
ViewProjection* viewProjection_ = nullptr;
};