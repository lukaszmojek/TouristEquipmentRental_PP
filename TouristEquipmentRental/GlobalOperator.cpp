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
	/* FONT */
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = w;                   // Width 
	cfi.dwFontSize.Y = h;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void GlobalOperator::CreateSeparator(int length, char sign) {
	cout << setfill(sign) << setw(length) << sign << endl; cout << endl;
}