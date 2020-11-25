#include "Buffer.h"
Buffer::Buffer(int pScreenWidth, int pScreenHeight)
{
	width = pScreenWidth, height = pScreenHeight;
	buffer = new wchar_t[width * height];
	for (int i = 0; i < width * height; i++) { buffer[i] = ' '; }
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
}
void Buffer::edit(int x, int y, wchar_t c)
{
	buffer[y * width + x] = c;
}
void Buffer::update()
{
	WriteConsoleOutputCharacter(hConsole, buffer, width * height, {0,0}, &dwBytesWritten);
}
void Buffer::del()
{
	delete[] buffer;
	buffer = nullptr;
}