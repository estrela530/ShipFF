#pragma once
#include "Player.h"

//	タイマークラス
class Score
{
public:
	//	初期化
	void Start();

	//	描画
	void Render();

	//　更新
	void Update();

	//スコア
	int _playerScore;

private:
	//	画像ハンドル
	int _numGrp;


	//プレイヤー
	Player _player;


	//	画像のサイズ
	int _imageSize;
};
