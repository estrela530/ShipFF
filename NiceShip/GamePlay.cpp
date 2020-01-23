#include "GamePlay.h"
#include "GraphFactory.h"
#include "DxLib.h"
#include <stdio.h>
#include <list>
#include "SceneManager.h"
using namespace std;

//	‰Šú‰»
void GamePlay::Initialize()
{
	//	ƒQ[ƒ€‰æ–Ê‚Ì”wŒi‰æ‘œ“Ç‚Ýž‚Ý
	_gameImage = GraphFactory::Instance().LoadGraph("img\\Sea.png");
	PlayMusic("sound\\gameplayBGM.mp3", DX_PLAYTYPE_LOOP);
	_player.Start();
	_port.Start();
	_score.Start();
	//_largeFish.Start();
	//_middleFish.Start();
	//_smallFish.Start();
	//_special.Start();
	position = 0;
	seconds = 0;
	score = 0;
	_score._playerScore = 0;
	IsSummonFlag = false;
}

//	XV
void GamePlay::Update()
{
	//	ƒQ[ƒ€‰æ–Ê‚ð•\Ž¦‚·‚é
	DrawGraph(position, 0, _gameImage, FALSE);
	DrawGraph(position - 1980, 0, _gameImage, FALSE);
	if (position >= 1980)
	{
		position = 0;
	}


	//DrawExtendGraph(0, 0, 1980, 1280, _gameImage, FALSE);

	//XV
	_player.Update();
	//_port.Update();

	//•`‰æ
	_player.Render();
	//_port.Render();


#pragma region ‹›ƒ‰ƒ“ƒ_ƒ€¶¬

	seconds += 1;

	if (seconds >= 120)
	{
		randomFish = GetRand(7);
		//randomFish = 1;
		IsSummonFlag = true;
	}

	if (IsSummonFlag)
	{
		switch (randomFish)
		{
		case 0:
			break;
		case 1:
			randomYPos = GetRand(7);
			//randomYPos = 1;
			if (randomYPos == 1)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);
				seconds = 0;
				randomYPos = 0;
				IsSummonFlag = false;
			}
			else if (randomYPos == 2)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);
				seconds = 0;
				randomYPos = 0;
				IsSummonFlag = false;
			}
			else if (randomYPos == 3)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);
				seconds = 0;
				randomYPos = 0;
				IsSummonFlag = false;

			}
			else if (randomYPos == 4)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);
				seconds = 0;
				randomYPos = 0;
				IsSummonFlag = false;

			}
			else if (randomYPos == 5)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);
				seconds = 0;
				randomYPos = 0;
				IsSummonFlag = false;

			}
			else if (randomYPos == 6)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);
				seconds = 0;
				randomYPos = 0;
				IsSummonFlag = false;

			}
			else if (randomYPos == 7)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);
				seconds = 0;
				randomYPos = 0;
				IsSummonFlag = false;

			}
			break;

		case 2:
			randomYPos = GetRand(7);

			if (randomYPos == 1)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);
				seconds = 0;
				randomYPos = 0;
				IsSummonFlag = false;
			}
			else if (randomYPos == 2)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 3)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);

				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 4)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);

				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 5)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);

				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 6)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);

				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 7)
			{
				LargeFish _largeFish;
				_largeFish.Start();
				_largeFish._position.y = randomYPos * 100;
				largeList.push_back(_largeFish);

				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			break;

		case 3:
			randomYPos = GetRand(7);

			if (randomYPos == 1)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 2)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);

				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 3)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);

				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 4)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 5)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 6)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 7)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			break;

		case 4:
			randomYPos = GetRand(7);

			if (randomYPos == 1)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 2)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 3)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 4)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 5)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 6)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 7)
			{
				MiddleFish _middleFish;
				_middleFish.Start();
				_middleFish._position.y = randomYPos * 100;
				middleList.push_back(_middleFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			break;

		case 5:
			randomYPos = GetRand(7);

			if (randomYPos == 1)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 2)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 3)
			{
				SmallFish _smallList;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 4)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 5)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 6)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 7)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			break;

		case 6:
			randomYPos = GetRand(7);

			if (randomYPos == 1)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 2)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 3)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 4)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 5)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 6)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 7)
			{
				SmallFish _smallFish;
				_smallFish.Start();
				_smallFish._position.y = randomYPos * 100;
				smallList.push_back(_smallFish);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			break;

		case 7:
			randomYPos = GetRand(7);

			if (randomYPos == 1)
			{
				Special _special;
				_special.Start();
				_special._position.y = randomYPos * 100;
				specialList.push_back(_special);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 2)
			{
				Special _special;
				_special.Start();
				_special._position.y = randomYPos * 100;
				specialList.push_back(_special);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 3)
			{
				Special _special;
				_special.Start();
				_special._position.y = randomYPos * 100;
				specialList.push_back(_special);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 4)
			{
				Special _special;
				_special.Start();
				_special._position.y = randomYPos * 100;
				specialList.push_back(_special);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 5)
			{
				Special _special;
				_special.Start();
				_special._position.y = randomYPos * 100;
				specialList.push_back(_special);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 6)
			{
				Special _special;
				_special.Start();
				_special._position.y = randomYPos * 100;
				specialList.push_back(_special);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}
			else if (randomYPos == 7)
			{
				Special _special;
				_special.Start();
				_special._position.y = randomYPos * 100;
				specialList.push_back(_special);
				seconds = 0;
				IsSummonFlag = false;
				randomYPos = 0;
			}

			break;
		}
	}

	//for (auto i = 0; i < largeList.size(); i++)
	//{
	//	/*for (auto l = largeList.begin(); l != largeList.end(); )
	//	{*/
	//	largeList[i].Update();
	//	largeList[i].Render();
	//	/*if ((*l)._position.x >= 1980)
	//	{
	//		delete *l;
	//	}*/
	//	//}
	//}

	for (auto i = 0; i < largeList.size();)
	{

		largeList[i].Update();
		largeList[i].Render();
		_player.Hit(largeList[i]);
		if (largeList[i]._position.x > 1980)
		{
			largeList.erase(largeList.begin() + i);

		}
		if (_player.hitLFlag)
		{
			/*_player.score = _player.score + 111;*/
 			_score._playerScore += 3000;

			largeList.erase(largeList.begin() + i);
			_player.hitLFlag = false;
		}
		else
		{
			i++;
		}

		
	}

	for (auto i = 0; i < middleList.size();)
	{
		middleList[i].Update();
		middleList[i].Render();
		_player.Hit(middleList[i]);
		if (middleList[i]._position.x > 1980)
		{
			middleList.erase(middleList.begin() + i);

		}
		if (_player.hitMFlag)
		{
			//_player.score = _player.score + 11;
			_score._playerScore += 1000;
			middleList.erase(middleList.begin() + i);
			_player.hitMFlag = false;
		}
		else
		{
			i++;
		}

		//std::string s = std::to_string(middleList[i]._position.y);
		//printfDx(s.data());
	}

	for (auto i = 0; i < smallList.size();)
	{
		smallList[i].Update();
		smallList[i].Render();
		_player.Hit(smallList[i]);
		if (smallList[i]._position.x > 1980)
		{
			smallList.erase(smallList.begin() + i);

		}
		if (_player.hitSFlag)
		{
			//_player.score = _player.score + 1;
			_score._playerScore += 500;

			smallList.erase(smallList.begin() + i);
			_player.hitSFlag = false;
		}
		else
		{
			i++;
		}

	}

	for (auto i = 0; i < specialList.size(); )
	{
		specialList[i].Update();
		specialList[i].Render();
		_player.Hit(specialList[i]);
		if (specialList[i]._position.x > 1980)
		{
			specialList.erase(specialList.begin() + i);

		}
		if (_player.hitSpFlag)
		{
			//_player.score = _player.score + 1111;
			_score._playerScore += 4000;
			specialList.erase(specialList.begin() + i);
			_player.hitSpFlag = false;
		}
		else
		{
			i++;
		}

	}
#pragma endregion

	//_largeFish.Update();
	//_middleFish.Update();
	//_smallFish.Update();
	//_special.Update();



	//_largeFish.Render();
	//_middleFish.Render();
	//_smallFish.Render();
	//_special.Render();


	position += 3;



	//std::string s = std::to_string(_player.score);
	//printfDx(s.data());

	_score.Update();
	_score.Render();

	if (_score._playerScore >= 50000)
	{
		SceneManager::Instance().LoadScene("Clear");
	}
}

//	‰ð•ú
void GamePlay::Release()
{
	StopSoundFile();
	GraphFactory::Instance().EraseGraph("img\\Sea.png");
}
