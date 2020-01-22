#include <DxLib.h>
#include "Port.h"
#include "GraphFactory.h"

//	‰Šú‰»ˆ—
void Port::Start()
{
	_grp = GraphFactory::Instance().LoadGraph("img\\minato.png");
	_size = Vector2D(600, 128);
	_position = Vector2D(500, 735);
}

//	•`‰æ
void Port::Render()
{
	LoadGraphScreen(static_cast<int>(_position.x),
		static_cast<int>(_position.y),
		"img\\minato.png", FALSE);
}

//	XV
void Port::Update()
{

}

void Port::Hit()
{

}

//	‰ğ•ú
void Port::Release()
{
}




