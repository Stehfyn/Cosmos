#include "Ambience.h"
#include <cstdlib>
#include <random>
void::Ambience::initRand()
{

}
void::Ambience::addStar()
{
	//instantiate a star into the stars[120] array
	if (starIndex == 120)
		starIndex = 0;
	//srand(rand(); //neato bug
	stars[starIndex].xPos = rand() % 80;
	stars[starIndex].yPos = 0;
	stars[starIndex].active = true;
	starIndex++;
	lastX = stars[starIndex].xPos;
}
void::Ambience::advanceStars(Buffer buffer)
{
	for (int i = 0; i < 120; i++)
		if (stars[i].active == true)
		{
			buffer.edit(stars[i].xPos, stars[i].yPos, L' ');
			stars[i].yPos++;
			if (stars[i].yPos == 30)
				deleteStar(i);
		}
}
void::Ambience::printStars(Buffer buffer)
{
	for (int i = 0; i < 120; i++)
		if (stars[i].active == true)
			buffer.edit(stars[i].xPos, stars[i].yPos, stars[i].character);
}
void::Ambience::deleteStar(int index)
{
	stars[index].active = false;
}