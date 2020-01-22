#include "Score.h"
#include "GraphFactory.h"
#include "Window.h"

//	�����J�n
void Score::Start()
{
	//	�摜��ǂݍ���
	_numGrp = GraphFactory::Instance().LoadGraph("number.png");

	//	�����̉摜�T�C�Y��ݒ�(60 x 60)
	_imageSize = 60;
}

void Score::Render()
{
	//2���܂ŕ\������
	for (auto dig = 0; dig < 6; dig++)
	{
		//	�]����v�Z���ꌅ�ڂ̐������Z�o
		auto num = _playerScore % 10;

		//	�摜��\������i�����ŉ摜�̍��W���킩��悤�Ɂj
		DrawRectGraph((Window::WindowWidth / 2) - dig * _imageSize,
			static_cast<int>(20), num* _imageSize, 0,
			_imageSize, _imageSize, _numGrp, TRUE);

		//���݂̎��Ԃ�10�Ŋ���A����������
		_playerScore = _playerScore / 10;
	}
}

void Score::Update()
{
	_playerScore = _player.score;
}
