#pragma once
#include "Player.h"

//	�^�C�}�[�N���X
class Score
{
public:
	//	������
	void Start();

	//	�`��
	void Render();

	//�@�X�V
	void Update();

private:
	//	�摜�n���h��
	int _numGrp;

	//�X�R�A
	int _playerScore;

	//�v���C���[
	Player _player;

	//	�摜�̃T�C�Y
	int _imageSize;
};
