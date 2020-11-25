#pragma once
#include "Windows.h"
class Buffer
{
public:
	Buffer(int pScreenWidth, int pScreenHeight);
	void edit(int x, int y, wchar_t c);
	void update();
	void del();
	wchar_t* get(){return buffer;}
private:
	wchar_t* buffer{};
	int width{};
	int height{};
	HANDLE hConsole{};
	DWORD dwBytesWritten{};
};