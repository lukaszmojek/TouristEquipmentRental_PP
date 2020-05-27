#include "GlobalOperator.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <iomanip>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


void GlobalOperator::Delay(int sec) {
	sleep_until(system_clock::now() + seconds(sec));
}

void GlobalOperator::SetColor(int nr) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, nr);
}

void GlobalOperator::SetFont(int h, int w) {
	CONSOLE_FONT_INFOEX consoleFont;
	consoleFont.cbSize = sizeof(consoleFont);
	consoleFont.nFont = 0;
	consoleFont.dwFontSize.X = w;                   // Width 
	consoleFont.dwFontSize.Y = h;                  // Height
	consoleFont.FontFamily = FF_DONTCARE;
	consoleFont.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &consoleFont);
}
void GlobalOperator::CreateSeparator(int length, char sign) {
	cout << setfill(sign) << setw(length) << sign << endl; cout << endl;
}