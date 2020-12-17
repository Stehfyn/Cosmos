#pragma once
#include "Buffer.h"
#include "Ambience.h"
#include "MainMenu.h"
#include "Keyboard.h"
#include "Gamepad.h"
#define MAX_DELAY_NUM 10
#define STAR_DELAY 3
#define CURSOR_DELAY 30
#define INPUT_DELAY 7
class GameState
{
public:
	GameState(int sScreenWidth, int sScreenHeight);
	Buffer getBuffer() { return buffer; }

	//Main Menu
	void mm_display();
	//================
	void mm_displayAmbience();
	void mm_displayTitle();
	void mm_displayModes();
	void mm_displayCursor();
	int mm_getInput(Keyboard, Gamepad);

private:
	Buffer buffer;
	Ambience ambience{};

	int selection{};
	int lastSelection{};
	bool selectionChange{};
	bool cursorVis{};
	struct delay
	{
		int star{ STAR_DELAY };

		int cursor{ CURSOR_DELAY };

		int inputDelay{ INPUT_DELAY };
		bool input{};
	}stateDelay;

	int ScreenWidth{};
	int ScreenHeight{};
};

