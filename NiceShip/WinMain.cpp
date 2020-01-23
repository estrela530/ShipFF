#include <DxLib.h>
#include <string>
#include "Window.h"
#include "SceneManager.h"
#include "GamePlay.h"
#include "Title.h"
#include "GameClear.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//	Windowモードの設定とWindowタイトルを設定する
	ChangeWindowMode(true);
	//SetMainWindowText("");

	//	画面サイズを設定
	SetGraphMode(Window::WindowWidth, Window::WindowHeight, 16);
	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;				// エラーが起きたら直ちに終了
	}

	//	描画先を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//	画面背景の色を設定する
	SetBackgroundColor(0, 0, 0);

	// シーンを追加する
	SceneManager::Instance().AddScene("Title", new Title);
	SceneManager::Instance().AddScene("Game", new GamePlay);
	SceneManager::Instance().AddScene("Clear", new GameClear);

	//	シーン管理クラスで開始シーンを登録
	SceneManager::Instance().StartScene("Title");
	//SceneManager::Instance().StartScene("Game");

	//	実行
	SceneManager::Instance().Update();

	//	解放処理
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了
}