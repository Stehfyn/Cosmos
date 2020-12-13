#include "Main_Menu.h"

void::Main_Menu::displayAmbience(int tickCounter, Buffer buffer)
{
	if (tickCounter % 4 == 0)
	{
		ambience.addStar();
		ambience.advanceStars(buffer);
	}
	ambience.printStars(buffer);
	//HUD line
	for (int i = 0; i < 80; i++)
		buffer.edit(i, 2, L'─');
}
void::Main_Menu::displayTitle(Buffer buffer)
{
	int xOffset{31};
	int yOffset{7};

	std::wstring top = L"┌─┐┌─┐┌─┐┌┬┐┌─┐┌─┐";
	std::wstring mid = L"│  │ │└─┐││││ │└─┐";
	std::wstring bot = L"└─┘└─┘└─┘┴ ┴└─┘└─┘";

	for (int i = 0; i < top.length(); i++)
		buffer.edit(i + xOffset, yOffset,top[i]);
	for (int i = 0; i < mid.length(); i++)
		buffer.edit(i + xOffset, 1 + yOffset, mid[i]);
	for (int i = 0; i < bot.length(); i++)
		buffer.edit(i + xOffset, 2 + yOffset, bot[i]);
}
void::Main_Menu::displayModes(Buffer buffer)
{
	int xOffset{35};
	int yOffset{14};

	std::wstring play{L"PLAY"};
	std::wstring practice{L"PRACTICE"};
	std::wstring highScores{L"HIGH SCORES"};
	std::wstring settings{L"SETTINGS"};
	std::wstring controls{L"CONTROLS"};
	std::wstring exit{L"EXIT"};

	for (int i = 0; i < play.length(); i++)
		buffer.edit(i + xOffset, yOffset, play[i]);
	for (int i = 0; i < practice.length(); i++)
		buffer.edit(i + xOffset, 2 + yOffset, practice[i]);
	for (int i = 0; i < highScores.length(); i++)
		buffer.edit(i + xOffset, 4 + yOffset, highScores[i]);
	for (int i = 0; i < settings.length(); i++)
		buffer.edit(i + xOffset, 6 + yOffset, settings[i]);
	for (int i = 0; i < controls.length(); i++)
		buffer.edit(i + xOffset, 8 + yOffset, controls[i]);
	for (int i = 0; i < exit.length(); i++)
		buffer.edit(i + xOffset, 10 + yOffset, exit[i]);
}