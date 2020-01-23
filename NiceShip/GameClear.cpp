#include <DxLib.h>
#include "GameClear.h"
#include "GraphFactory.h"
#include "SceneManager.h"

//	初期化
void GameClear::Initialize()
{
	//	タイトルの背景の画像読み込み
	_clearImage = GraphFactory::Instance().LoadGraph("img\\result.png");
}

//	更新
void GameClear::Update()
{
	//	タイトル画面を表示する
	//DrawGraph(0, 0, _titleImage, TRUE);
	DrawExtendGraph(0, 0, 1600, 1280, _clearImage, FALSE);

	//	キー入力を更新
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key & PAD_INPUT_10) {
		//	シーンをゲームシーンに切り替える
		SceneManager::Instance().LoadScene("Title");
	}
}

//	解放
void GameClear::Release()
{
	GraphFactory::Instance().EraseGraph("img\\result.png");
}
