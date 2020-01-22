#include <DxLib.h>
#include "Special.h"
#include "GraphFactory.h"

//	‰Šú‰»ˆ—
void Special::Start()
{
	_grp = GraphFactory::Instance().LoadGraph("img\\kirakira.png");
	_size = Vector2D(600, 128);
	_position = Vector2D(0, 735);
	_velocity = Vector2D(0, 0);

	weight = 0.1;
	score = 4000;

}

//	•`‰æ
void Special::Render()
{
	if (_position.x < 500)
	{
		LoadGraphScreen(static_cast<int>(_position.x),
			static_cast<int>(_position.y),
			"img\\silhouette.png", TRUE);
	}
	else if (_position.x >= 500)
	{
		LoadGraphScreen(static_cast<int>(_position.x),
			static_cast<int>(_position.y),
			"img\\kirakira.png", TRUE);

	}

}

//	XV
void Special::Update()
{

	_position.x += 4;


}

//	‰ğ•ú
void Special::Release()
{
}


void Special::Hit()
{

}



