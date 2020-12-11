#include "HUD.h"
void::HUD::displayScore(int score, Buffer buffer)
{
	int xOffset{ 39 };
	int yOffset{ 1 };
	scoreString = std::to_string(score);
	int scoreLength = scoreString.length();
	
	if (scoreLength == 3 || scoreLength == 4)
		xOffset -= 1;
	if (scoreLength == 5)
		xOffset -= 2;
	
	//scoreArray = new wchar_t[scoreString.length()];
	for(int i = 0; i < scoreLength; i++)
		buffer.edit(i + xOffset, yOffset, scoreString[i]);
}
void::HUD::displayEnemies(int remaining, Buffer buffer)
{
	int xOffset{ 68 };
	int yOffset{ 1 };

	currRemainString = std::to_string(remaining);

	int currLength = currRemainString.length(), lastLength = lastRemainString.length();

	if (currLength < lastLength)
		buffer.edit(xOffset + 1, yOffset, L' ');
	
	int remainLength = currRemainString.length();

	std::wstring enemyString = L"Enemies: ";
	for (int i = 0; i < enemyString.length(); i++)
		buffer.edit(59 + i, 1, enemyString[i]);

	for (int i = 0; i < remainLength; i++)
		buffer.edit(i + xOffset, yOffset, currRemainString[i]);

	lastRemainString = std::to_string(remaining);
}
void::HUD::displayAccuracy(double accuracy, Buffer buffer)
{
	int xOffset{};
	int yOffset{};

	currAccString = std::to_string(accuracy);
	for (int i = 0; i < currAccString.length(); i++)
		buffer.edit(i + xOffset, yOffset, currAccString[i]);
}