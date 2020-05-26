#include "LoginPanel.h"
#include <Windows.h>
#include <iomanip>
#include <string>

using namespace std;

LoginPanel::LoginPanel() {
	isRegister = false;
}

void LoginPanel::ShowPanel(){

    /*Seting font size*/
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 24;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    /*Seting font color*/
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 5);


    cout << setfill('*') << setw(30) << '*' << endl; cout << endl;
    SetConsoleTextAttribute(hConsole, 4);
        if (isRegister) {
            cout << setfill(' ') << setw(20) << "Register Panel" << endl;
        }
        else {
            cout << setfill(' ') << setw(20) << "Login Panel" << endl;
        }
    SetConsoleTextAttribute(hConsole, 5);
    cout << endl; cout << setfill('*') << setw(30) << '*' << endl; cout << endl;
}

string LoginPanel::Login() {
    string userID, password;
    cout << "USER ID:  ";
    cin >> userID;
    cout << endl;
    cout << "PASSWORD:  ";
    cin >> password;

    return userID, password;
}