#pragma once
#include "Buffer.h"
class Game
{
public:
	void getInput(Buffer);
	void shoot();
	void check(Buffer);
	void printPlayer(Buffer);
private:
	struct Player
	{
		int xPos{39};
		int yPos{27};
		int lives{ 3 };
		int inventory[10]{};
		wchar_t character{ L'^' };
	};
	struct Enemy
	{
		int xPos{};
		int yPos{};
		int health{};
		wchar_t character{};
	};
	struct Laser
	{
		int xPos{};
		int yPos{};
		wchar_t character{};
		bool dual{};
		bool active{};
	};
	struct Item
	{
		int xPos{};
		int yPos{};
		wchar_t item{};
	};

	Player player{};
	Enemy enemyList[120];
	Laser laserList[120];
	Item itemList[120];
	int laserIndex{};
	int bKey[4];
};