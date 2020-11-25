//Stephen Foster

#include <thread>
#include <chrono>
#include "Buffer.h"
#include "Ambience.h"
#include "Game.h"

#define TICK_RATE 16.67ms //60 fps
using namespace std;

int main()
{
	//init buffer
	const int ScreenWidth{ 80 }, ScreenHeight{ 30 };

	Buffer buffer(ScreenWidth, ScreenHeight);
	Ambience ambience{};
	Game game{};

	int tickCounter{};
	
	//game loop
	bool run = true;
	while (run)
	{
		//take clock time
		//===============
		auto start = std::chrono::high_resolution_clock::now();

		//get user input
		game.getInput(buffer);
		
		//--input buffer

		//get game logic input
		//--game logic buffer
		//compare and calculate next frame
		
		if (tickCounter % 1 == 0)
		{
			ambience.addStar();
			ambience.advanceStars(buffer);
		}
		ambience.printStars(buffer);


		//===============
		//take clock time
		//fix framerate based on elapsed
		//debug - draw player
		game.printPlayer(buffer);
		//update frame with next frame
		buffer.update();
		tickCounter++;
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::microseconds>(start - end);
		this_thread::sleep_for(TICK_RATE - elapsed);
	}
	
	return 0;
}