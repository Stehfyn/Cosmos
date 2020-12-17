//Stephen Foster

#include <iostream>
#include <thread>
#include <chrono>
#include "Buffer.h"
#include "Ambience.h"
#include "Game.h"
#include "HUD.h"
#include "Main_Menu.h"
#include "GameState.h"
#include "Keyboard.h"
#include "Gamepad.h"
#include <process.h>

#define TICK_RATE 16.67ms //60 fps
const int ScreenWidth{ 80 }, ScreenHeight{ 30 };
 //controller 1

using namespace std;

int main()
{
	GameState MainMenu(ScreenWidth, ScreenHeight);
	//GameState Practice(ScreenWidth, ScreenHeight);
	//GameState Game(ScreenWidth, ScreenHeight);

	Keyboard keyboard;
	Gamepad gamepad(1);
	int state{-1};
	while (state != 4) 
	{
		switch (state)
		{
		case -1:
		{
			while (state == -1)
			{
				auto start = std::chrono::high_resolution_clock::now();
				state = MainMenu.mm_getInput(keyboard, gamepad);
				MainMenu.mm_display();
				gamepad.Update();
				MainMenu.getBuffer().update();
				auto end = chrono::high_resolution_clock::now();
				auto elapsed = chrono::duration_cast<chrono::microseconds>(start - end);
				this_thread::sleep_for((TICK_RATE) / 2);
			}
			//code cleanup
			break;
		}
		case 0:
		{
			Buffer buffer(ScreenWidth, ScreenHeight);
			Ambience ambience{};
			Game game{};
			HUD hud{};
			//buffer.setWindow();
			int tickCounter{};

			//game loop
			bool run = true;
			while (run)
			{
				//take clock time
			//===============
				auto start = std::chrono::high_resolution_clock::now();
				//get user input
				game.getInput(buffer, tickCounter);
				//game.check(buffer);
				//--input buffer

				//get game logic input
				//--game logic buffer
				//compare and calculate next frame
				if (tickCounter % 4 == 0)
				{
					ambience.addStar();
					ambience.advanceStars(buffer);
				}
				if (tickCounter % 1 == 0)
				{
					game.advanceLaser(buffer);
				}
				ambience.printStars(buffer);
				if (tickCounter % 30 == 0)
				{
					game.advanceEnemy(buffer);
				}
				if (tickCounter % 60 == 0)
				{
					game.addEnemy(rand() % 80, 0, 1, L'?');
				}
				game.check(buffer);
				//===============
				//take clock time
				//fix framerate based on elapsed
				//debug - draw player

				game.printEnemy(buffer);
				game.printLaser(buffer);
				game.printPlayer(buffer);
				//update frame with next frame
				//game.addScore(1);
				hud.displayScore(game.getScore(), buffer);
				hud.displayEnemies(game.getRemaining(), buffer);
				hud.displayAccuracy(game.calcAccuracy(), buffer);
				hud.displayLine(buffer);
				buffer.update();
				tickCounter++;
				auto end = chrono::high_resolution_clock::now();
				auto elapsed = chrono::duration_cast<chrono::microseconds>(start - end);
				this_thread::sleep_for((TICK_RATE - elapsed) / 2);
			}
			break;
		}
		}
	}
	/*Buffer buffer(ScreenWidth, ScreenHeight);
	Ambience ambience{};
	Game game{};
	HUD hud{};
	//buffer.setWindow();
	int tickCounter{};

	//game loop
	bool run = true;
	while (run)
	{
     		//take clock time
		//===============
		auto start = std::chrono::high_resolution_clock::now();
		//get user input
		game.getInput(buffer, tickCounter);
		//game.check(buffer);
		//--input buffer

		//get game logic input
		//--game logic buffer
		//compare and calculate next frame
		if (tickCounter % 4 == 0)
		{
			ambience.addStar();
			ambience.advanceStars(buffer);
		}
		if (tickCounter % 1 == 0)
		{
			game.advanceLaser(buffer);
		}
		ambience.printStars(buffer);
		if (tickCounter % 30 == 0)
		{
			game.advanceEnemy(buffer);
		}
		if (tickCounter % 60 == 0)
		{
			game.addEnemy(rand() % 80, 0, 1, L'?');
		}
		game.check(buffer);
		//===============
		//take clock time
		//fix framerate based on elapsed
		//debug - draw player

		game.printEnemy(buffer);
		game.printLaser(buffer);
		game.printPlayer(buffer);
		//update frame with next frame
		//game.addScore(1);
		hud.displayScore(game.getScore(), buffer);
		hud.displayEnemies(game.getRemaining(), buffer);
		hud.displayAccuracy(game.calcAccuracy(), buffer);
		hud.displayLine(buffer);
		buffer.update();
		tickCounter++;
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::microseconds>(start - end);
		this_thread::sleep_for((TICK_RATE - elapsed)/2);
	}*/
	//system("taskkill /IM Cosmos.exe /F");
	return 0;
}