#include "Score.h"
#include "GraphFactory.h"
#include "Window.h"

//	調理開始
void Score::Start()
{
	//	画像を読み込む
	_numGrp = GraphFactory::Instance().LoadGraph("img\\number.png");

	//	数字の画像サイズを設定(60 x 60)
	_imageSize = 60;
}


void Score::Update()
{
	
}

void Score::Render()
{
	int count = _playerScore;
	//6桁まで表示する
	for (auto dig = 0; dig < 6; dig++)
	{
		//	余りを計算し一桁目の数字を算出
 		auto num = count %10;

		//std::string s = std::to_string(_playerScore);
		//printfDx(s.data());

		//	画像を表示する（桁数で画像の座標がわかるように）
		DrawRectGraph((Window::WindowWidth / 2) - dig* _imageSize,static_cast<int>(20),
			num* _imageSize, 0,
			_imageSize,_imageSize,
			_numGrp,
			TRUE);
		count /= 10;
		//現在の時間を10で割り、桁を下げる
		//_playerScore = _playerScore / 10;
		//_playerScore = 5;
	}
}

