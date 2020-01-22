#pragma once
#include "Vector2D.h"
#include "GameObject.h"

//	�v���C���[�N���X
//	��GameObject�N���X���p������
class Player : public GameObject
{
public:
	//	�J�n
	//	��override�C���q���g�p���邱�Ƃ�
	//	���̃����o�֐������N���X�ɑ��݂��Ȃ��ꍇ�A�G���[���o�͂���
	void Start() override;

	//	�`��
	void Render()  override;

	//	�X�V
	void Update()  override;

	// ���
	void Release()  override;

	//�����蔻��
	void Hit() override;

	//�{�^��
	int OnButton;

	// ���
	void UpdatePosition(bool hitX, bool hitY);

	//	���x���擾
	Vector2D Velocity()
	{
		return _velocity;
	}
	Vector2D Angle()
	{
		return _angle;
	}

	VECTOR PlayerPos()
	{
		return playerPos;
	}
	VECTOR Pos()
	{
		return _pos;
	}
	VECTOR Vec()
	{
		return _vec;
	}

public:
	//	�摜�n���h��
	int _grp;
	float playerWid;
	float playerHei;
	float maxLimit;
	float minLimit;
	float upSpeed;
	float downSpeed;
	float stop;
	bool hitFlag;

	Vector2D _velocity;
	Vector2D _angle;
	VECTOR playerPos;
	VECTOR _pos;
	VECTOR _vec;

	//LargeFish L;

};