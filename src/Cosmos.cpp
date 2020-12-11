//Stephen Foster

#include <thread>
#include <chrono>
#include "Buffer.h"
#include "Ambience.h"
#include "Game.h"
#include "HUD.h"

#define TICK_RATE 16.67ms //60 fps
using namespace std;

int main()
{
	//init buffer
	const int ScreenWidth{ 80 }, ScreenHeight{ 30 };

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
		if (tickCounter % 2 == 0)
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
		game.addScore(1);
		hud.displayScore(game.getScore(), buffer);
		hud.displayEnemies(game.getRemaining(), buffer);
		hud.displayAccuracy(game.calcAccuracy(), buffer);
		buffer.update();
		tickCounter++;
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::microseconds>(start - end);
		this_thread::sleep_for((TICK_RATE - elapsed)/2);
	}
	return 0;
}