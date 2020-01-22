#pragma once
#include "Vector2D.h"
#include "DxLib.h"

//	ゲームオブジェクトクラス
class GameObject
{
public:
	//	コンストラクタ
	GameObject() : _position(0, 0), _size(0, 0) {}

	//	開始
	virtual void Start() = 0;

	//	描画
	virtual void Render() = 0;

	//	更新
	virtual void Update() = 0;

	//	解放
	virtual void Release() = 0;

	//当たり判定
	virtual void Hit() = 0;

	//　

	//	※Tipsメンバ関数にconstを付与する事で
	//	その関数内でのメンバ変数の変更を禁止にする
	Vector2D Position() const { return _position; }
	Vector2D Size() const { return _size; }

	float Radius() const { return _radius; }
	float Rotate() const { return _rotate; }
	float Sin() const { return _sin; }
	float Cos() const { return _cos; }
	float Speed() const { return _speed; }

	VECTOR PlayerPos() { return playerPos; }
	VECTOR Pos() { return _pos; }
	VECTOR Vec() { return _vec; }

public:
	Vector2D _position;		//	座標
	Vector2D _size;			//	サイズ

	VECTOR playerPos;
	VECTOR _pos;
	VECTOR _vec;

	float _radius;			//	半径
	float _rotate;          //  回転
	float _speed;         //
	float _sin;           //  
	float _cos;           //  

	int maxLimit;
	int minLimit;
	int upSpeed;
	int downSpeed;

	float weight; // 重さ
	float weightL; // 重さ
	float weightM; // 重さ
	float weightS; // 重さ
	float weightSp; // 重さ

	int score;// スコア
};