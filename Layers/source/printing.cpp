#include "printing.h"

u8 getRand(u8 num)
{
	return (rand() % num);
}

void printToConsole(u8 x, u8 y, std::string color, std::string sentence)
{
	std::string position = "\x1b[" + std::to_string(y + 1) + ";" + std::to_string(x + 1) + "H";
	std::cout <<  position + color + sentence;
	std::cout.flush();
}

void drawBackground(u8 width, u8 height, std::string color)
{
	for (u8 i = 0; i < width; i++)
	{
		for (u8 j = 0; j < height; j++)
		{
			printToConsole(i, j, color);
		}
	}
}
