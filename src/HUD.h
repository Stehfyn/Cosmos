#pragma once
#include <string>
#include "Buffer.h"
#include "Game.h"
class HUD
{
public:
	void displayScore(int, Buffer);
	void displayEnemies(int, Buffer);
	void displayAccuracy(double, Buffer);
private:
	std::string currAccString{};
	std::string lastAccString{};

	std::string scoreString{};

	std::string currRemainString{};
	std::string lastRemainString{};

	wchar_t* scoreArray{};
};