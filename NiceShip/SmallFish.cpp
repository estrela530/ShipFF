#include <DxLib.h>
#include "SmallFish.h"
#include "GraphFactory.h"

//	‰Šú‰»ˆ—
void SmallFish::Start()
{
	_grp = GraphFactory::Instance().LoadGraph("img\\fishC.png");
	_size = Vector2D(128, 128);
	_position = Vector2D(0, 0);

	weight = 0.25;
	score = 500;

}

//	•`‰æ
void SmallFish::Render()
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
			"img\\fishC.png", TRUE);
	}
}

//	XV
void SmallFish::Update()
{
	_position.x += 2;

}

//	‰ğ•ú
void SmallFish::Release()
{
}

void SmallFish::Hit()
{

}




