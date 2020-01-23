#include <DxLib.h>
#include "Player.h"
#include "GraphFactory.h"
#include <cmath>
#include"LargeFish.h"
#include <cstdio>

//	初期化処理
void Player::Start()
{
	//	画像を読み込む
	_numGrp = GraphFactory::Instance().LoadGraph("img\\number.png");

	_SoundHandle = LoadSoundMem("sound\\fish.mp3");
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

	playerHei = 128 / 2;  //プレイヤーの横幅
	playerWid = 256 / 2; //プレイヤーの縦幅

	maxLimit = 5;
	minLimit = 1;
	upSpeed = 0.2;
	downSpeed = 0.1;
	stop = 0;

	weight = 0;
	weightL = 0.8;
	weightM = 0.4;
	weightS = 0.25;
	weightSp = 0.1;
	score = 0;

	hitLFlag = FALSE;
	hitMFlag = FALSE;
	hitSFlag = FALSE;
	hitSpFlag = FALSE;

}



//	解放
void Player::Release()
{
}

void Player::Hit(LargeFish l)
{
	auto x = abs((_pos.x + playerWid / 2) - (l._position.x + l._size.x / 2));
	auto y = abs((_pos.y + playerHei / 2) - (l._position.y + l._size.y / 2));

	if (x < (playerWid + l._size.x) / 2 && y < (playerHei + l._size.y) / 2)
	{
		//PlaySoundFile("sound\\fish", DX_PLAYTYPE_NORMAL);
		PlaySoundMem(_SoundHandle, DX_PLAYTYPE_BACK, true);
		hitLFlag = TRUE;
	}
}

void Player::Hit(MiddleFish m)
{
	auto x = abs((_pos.x + playerWid / 2) - (m._position.x + m._size.x / 2));
	auto y = abs((_pos.y + playerHei / 2) - (m._position.y + m._size.y / 2));

	if (x < (playerWid + m._size.x) / 2 && y < (playerHei + m._size.y) / 2)
	{
		//PlaySoundFile("sound\\fish", DX_PLAYTYPE_NORMAL);
		PlaySoundMem(_SoundHandle, DX_PLAYTYPE_BACK, true);
		hitMFlag = TRUE;
	}

}

void Player::Hit(SmallFish s)
{
	auto x = abs((_pos.x + playerWid / 2) - (s._position.x + s._size.x / 2));
	auto y = abs((_pos.y + playerHei / 2) - (s._position.y + s._size.y / 2));

	if (x < (playerWid + s._size.x) / 2 && y < (playerHei + s._size.y) / 2)
	{
		//PlaySoundFile("sound\\fish", DX_PLAYTYPE_NORMAL);

		PlaySoundMem(_SoundHandle, DX_PLAYTYPE_BACK, true);
		hitSFlag = TRUE;
	}

}

void Player::Hit(Special sp)
{
	auto x = abs((_pos.x + playerWid / 2) - (sp._position.x + sp._size.x / 2));
	auto y = abs((_pos.y + playerHei / 2) - (sp._position.y + sp._size.y / 2));

	if (x < (playerWid + sp._size.x) / 2 && y < (playerHei + sp._size.y) / 2)
	{
		//PlaySoundFile("sound\\fish", DX_PLAYTYPE_NORMAL);

		PlaySoundMem(_SoundHandle, DX_PLAYTYPE_BACK, true);
		hitSpFlag = TRUE;
	}

}

void Player::Hit()
{

}

//	更新
void Player::Update()
{


	//	キー入力を更新
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

	/*if (hitLFlag)
	{
		DrawString(0, 0, "当たった!", GetColor(255, 0, 0));
		weight + weightL;
		_vec.x - weight;
		hitLFlag = false;
	}
	if (hitMFlag)
	{
		DrawString(0, 0, "当たった!", GetColor(255, 0, 0));
		weight + weightM;
		_vec.x - weight;
		hitMFlag = false;
	}
	if (hitSFlag)
	{
		DrawString(0, 0, "当たった!", GetColor(255, 0, 0));
		weight + weightS;
		_vec.x - weight;
		hitSFlag = false;
	}
	if (hitSpFlag)
	{
		DrawString(0, 0, "当たった!", GetColor(255, 0, 0));
		weight + weightSp;
		_vec.x - weight;
		hitSpFlag = false;
	}*/

	playerPos = VGet(playerPos.x, playerPos.y, 0);
	//	移動量をクリア	
	_velocity = Vector2D(0, 0);

	//	右キーで右に移動
	if (key & PAD_INPUT_RIGHT)
	{
		//_velocity.x += 2;
		_rotate += 0.02;
	}

	//	左キーで右に移動
	if (key & PAD_INPUT_LEFT)
	{
		_rotate -= 0.02;
	}

	//スペースキーが押されたら前進
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		//_velocity.y -= 2;
		_vec.x += upSpeed;
		if (_vec.x >= maxLimit)
		{
			if (hitLFlag)
			{
				DrawString(0, 0, "当たった!", GetColor(255, 0, 0));
				weight = weight + weightL;
				_vec.x = _vec.x - weight;
				//score = score + _largeFish.score;
				//hitLFlag = false;
			}
			if (hitMFlag)
			{
				DrawString(0, 0, "当たった!", GetColor(255, 0, 0));
				weight = weight + weightM;
				_vec.x = _vec.x - weight;
				//score = score + _middleFish.score;

				//hitMFlag = false;
			}
			if (hitSFlag)
			{
				DrawString(0, 0, "当たった!", GetColor(255, 0, 0));
				weight = weight + weightS;
				_vec.x = _vec.x - weight;
				//score = score + _smallFish.score;

				//hitSFlag = false;
			}
			if (hitSpFlag)
			{
				DrawString(0, 0, "当たった!", GetColor(255, 0, 0));
				weight = weight + weightSp;
				_vec.x = _vec.x - weight;
				//score = score + _special.score;

				//hitSpFlag = false;
			}
			_vec.x = maxLimit;

			//std::string s = std::to_string(_vec.x);
			//printfDx(s.data());
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

	//6桁まで表示する
	//for (auto dig = 0; dig < 6; dig++)
	//{
	//	auto num = score % 10;
	//	DrawRectGraph(300 - dig * 60, static_cast<int>(20),
	//		num * 60, 0,
	//		60, 60,
	//		_numGrp,
	//		TRUE);

	//	//現在の時間を10で割り、桁を下げる
	//	score=score / 10;
	//}
	//	画像を表示する（桁数で画像の座標がわかるように）
}


//void Player::Hit()
//{
//	LargeFish la;
//	auto x = abs((_pos.x + playerWid / 2) - (la._position.x + la._size.x / 2));
//	auto y = abs((_pos.y+ playerHei / 2) - ( la._position.y+ la._size.y / 2));
//
//	if (x < (playerWid + la._size.x) / 2 && y < (playerHei + la._size.y) / 2)
//	{
//		hitFlag = TRUE;
//	}
//}


//	描画
void Player::Render()
{
	//	プレイヤーを描画
	/*DrawRectGraph(static_cast<int>(_position.x),
		static_cast<int>(_position.y), 0, 64,
		static_cast<int>(_size.x),
		static_cast<int>(_size.y), _grp, TRUE);*/

		/*LoadGraphScreen(static_cast<int>(_position.x),
			static_cast<int>(_position.y),
			"img\\red.png", FALSE);*/

			//DrawBox(_pos.x - 70, _pos.y - 70, _pos.x + 70, _pos.y + 70, GetColor(255, 0, 0), FALSE);


			//途中
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


