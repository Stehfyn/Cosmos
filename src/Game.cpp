#include "Game.h"
#include "Buffer.h"
#include "Windows.h"
void::Game::getInput(Buffer buffer)
{
	for (int k = 0; k < 4; k++)								// L R S
		bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x25\x27\x20"[k]))) != 0;
	if (bKey[0])
	{
		buffer.edit(player.xPos, player.yPos, L' ');
		player.xPos--;
	}
	if (bKey[1])
	{
		buffer.edit(player.xPos, player.yPos, L' '); 
		player.xPos++;
	}
	if (bKey[2])
	{
		shoot();
	}
}
void::Game::shoot()
{
	//add laser
	if (laserIndex == 120)
		laserIndex == 0;
	laserList[laserIndex].xPos = player.xPos;
	laserList[laserIndex].yPos = player.yPos - 1; //can do direct y because player will be overwrite the laser
	laserList[laserIndex].character = L'|';
	laserList[laserIndex].active = true;
	laserIndex++;
}
void::Game::check(Buffer buffer)
{
	
}
void::Game::printPlayer(Buffer buffer)
{
	buffer.edit(player.xPos, player.yPos, player.character);
}