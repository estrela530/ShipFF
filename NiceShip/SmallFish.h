#pragma once
#include "Vector2D.h"
#include "GameObject.h"

//	プレイヤークラス
//	※GameObjectクラスを継承する
class SmallFish : public GameObject
{
public:
	//	開始
	//	※override修飾子を使用することで
	//	そのメンバ関数が基底クラスに存在しない場合、エラーを出力する
	void Start() override;

	//	描画
	void Render()  override;

	//	更新
	void Update()  override;

	// 解放
	void Release()  override;

	//当たり判定
	void Hit() override;

	//ボタン
	int OnButton;

	// 解放
	void UpdatePosition(bool hitX, bool hitY);

	//	速度を取得
	Vector2D Velocity() {
		return _velocity;
	}
public:
	//	画像ハンドル
	int _grp;

	Vector2D _velocity;
	Vector2D _position;
};