#include <DxLib.h>
#include "LargeFish.h"
#include "GraphFactory.h"
#include "Player.h"
#include <cmath>

//	èâä˙âªèàóù
void LargeFish::Start()
{
	_grp = GraphFactory::Instance().LoadGraph("img\\fishA.png");
	_size = Vector2D(128, 128);
	_position = Vector2D(100, 735);
	_velocity = Vector2D(0, 0);

	weight = 0.8;
	score = 3000;
}

//	ï`âÊ
void LargeFish::Render()
{
	if (_position.x < 500)
	{
		LoadGraphScreen(static_cast<int>(_position.x),
			static_cast<int>(_position.y),
			"img\\silhouette.png", TRUE);
	}
	else if (_position.x >= 500 && _position.x <= 1980)
	{
		LoadGraphScreen(static_cast<int>(_position.x),
			static_cast<int>(_position.y),
			"img\\fishA.png", TRUE);

	}

}

//	çXêV
void LargeFish::Update()
{

	_position.x += 2;

	//if (_position.x >= 1980)
	//{
	//	delete
	//}

}

void LargeFish::Hit()
{
	Player pl;
	auto x = abs((_pos.x + pl.playerWid / 2) - (_position.x + _size.x / 2));
	auto y = abs((_pos.y + pl.playerHei / 2) - (_position.y + _size.y / 2));

	if (x < (pl.playerWid + _size.x) / 2 && y < (pl.playerHei + _size.y) / 2)
	{
		DrawString(0, 0, "ìñÇΩÇ¡ÇΩ!", GetColor(255, 0, 0));
	}
}

//	âï˙
void LargeFish::Release()
{


}




