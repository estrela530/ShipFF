#include <DxLib.h>
#include "Title.h"
#include "GraphFactory.h"
#include "SceneManager.h"

//	初期化
void Title::Initialize()
{
	//	タイトルの背景の画像読み込み
	_titleImage = GraphFactory::Instance().LoadGraph("img\\ShipTitle.png");
}

//	更新
void Title::Update()
{
	//	タイトル画面を表示する
	//DrawGraph(0, 0, _titleImage, TRUE);
	DrawExtendGraph(0, 0, 1600, 1280, _titleImage, FALSE);

	//	キー入力を更新
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key & PAD_INPUT_10) {
		//	シーンをゲームシーンに切り替える
		SceneManager::Instance().LoadScene("Game");
	}
}

//	解放
void Title::Release()
{
	GraphFactory::Instance().EraseGraph("img\\ShipTitle.png");
}
