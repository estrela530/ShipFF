#include <DxLib.h>
#include "Player.h"
#include "GraphFactory.h"
#include <cmath>
#include"LargeFish.h"
#include <cstdio>

//	����������
void Player::Start()
{
	_grp = GraphFactory::Instance().LoadGraph("img\\PlayerShip.png");
	_size = Vector2D(64, 64);
	_radius = 16;
	_position = Vector2D(500, 500);
	_velocity = Vector2D(0, 0);
	_rotate = 0;
	_speed = 2;
	_angle = Vector2D(0, 0);
	_sin = 0;
	_cos = 0;
	playerPos.x = 100;
	playerPos.y = 100;
	_vec.x = 0; 
	_vec.y = 0; 

	playerHei = 128/2;  //�v���C���[�̉���
	playerWid = 256/2; //�v���C���[�̏c��

	maxLimit = 5;
	minLimit = 1;
	upSpeed = 0.2;
	downSpeed = 0.1;
	stop = 0;

	hitFlag = FALSE;
}


//	�X�V
void Player::Update()
{
	//	�L�[���͂��X�V
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	//static int inputFrame = 0;
	VECTOR MoveAngle;
	//VECTOR speed1;
	_sin = sin(_rotate);
	_cos = cos(_rotate);

	MoveAngle.x = _vec.x * _cos - _vec.y * _sin;
	MoveAngle.y = _vec.x * _sin + _vec.y * _cos;

	/*MoveAngle.x = _velocity.x * _cos - _velocity.y * _sin;
	MoveAngle.y = _velocity.x * _sin + _velocity.y * _cos;*/


	playerPos = VGet(playerPos.x, playerPos.y, 0);
	//	�ړ��ʂ��N���A	
	_velocity = Vector2D(0, 0);

	//	�E�L�[�ŉE�Ɉړ�
	if (key & PAD_INPUT_RIGHT)
	{
		//_velocity.x += 2;
		_rotate += 0.02;
	}

	//	���L�[�ŉE�Ɉړ�
	if (key & PAD_INPUT_LEFT)
	{
		_rotate -= 0.02;
	}

	//�X�y�[�X�L�[�������ꂽ��O�i
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		//_velocity.y -= 2;
		_vec.x += upSpeed;
		if (_vec.x >= maxLimit)
		{
			_vec.x = maxLimit;
		}
	}
	else if (CheckHitKey(KEY_INPUT_SPACE) == FALSE)
	{
		_vec.x -= downSpeed;
		if (_vec.x <= stop)
		{
			_vec.x = stop;
		}
	}


	playerPos = VAdd(playerPos, MoveAngle);
	_pos = playerPos;
	//_position += _velocity;
}

//	���
void Player::Release()
{
}

void Player::Hit()
{
	LargeFish la;
	auto x = abs((_pos.x + playerWid / 2) - (la._position.x + la._size.x / 2));
	auto y = abs((_pos.y+ playerHei / 2) - ( la._position.y+ la._size.y / 2));

	if (x < (playerWid + la._size.x) / 2 && y < (playerHei + la._size.y) / 2)
	{
		hitFlag = TRUE;
	}
}


//	�`��
void Player::Render()
{
	//	�v���C���[��`��
	/*DrawRectGraph(static_cast<int>(_position.x),
		static_cast<int>(_position.y), 0, 64,
		static_cast<int>(_size.x),
		static_cast<int>(_size.y), _grp, TRUE);*/

		/*LoadGraphScreen(static_cast<int>(_position.x),
			static_cast<int>(_position.y),
			"img\\red.png", FALSE);*/

			//�r��
	DrawRotaGraph
	(
		static_cast<int>(_pos.x),
		static_cast<int>(_pos.y),
		0.5,
		_rotate,
		_grp,
		TRUE,
		FALSE
	);
	
	DrawBox(_pos.x-70, _pos.y-70, _pos.x+70, _pos.y+70, GetColor(255, 0, 0), FALSE);

	if (hitFlag)
	{
		DrawString(0, 0, "��������!", GetColor(255, 0, 0));
	}
	

	/*DrawRotaGraph
	(
		static_cast<int>(_position.x),
		static_cast<int>(_position.y),
		1,
		_rotate,
		_grp,
		FALSE,
		FALSE
	);*/
}


