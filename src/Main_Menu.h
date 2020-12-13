#pragma once
#include "Buffer.h"
#include "Ambience.h"
#include <string>
class Main_Menu
{
public:
	//display Ambient elements (stars, HUD line)
	//game occurring in the background
	//display modes

	void displayAmbience(int, Buffer);
	void displayTitle(Buffer);
	void displayModes(Buffer);
	void displayCursor(Buffer);

	
private:
	Ambience ambience{};
};

