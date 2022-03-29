/**
 *
 *	@file: mainMenu.cpp
 *	@desc: Main menu code file for RGBconv.
 *	@author: Jeremy B.
 *	@date: 16 May 2020
 *
 *	This file is licensed under the BSD License: enter requisite licensing bullshit here.
 *
 */

#include <iostream>
#include <limits>
#include "mainMenu.hpp"
#include "convert.hpp"

using namespace std;

void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void mainMenu()
{
    int response = 0;
    while (true)
    {
        Clear();
        cout << "=============================" << endl
             << "RGB Converter alpha v0.2.2" << endl
             << "============================" << endl
             << "1. Convert Hex to Decimal" << endl
             << "2. Convert Decimal to Hex" << endl
             << "3. Clausewitz Engine RGB conversion" << endl
             << "9 or 0. Exit" << endl
             << "=============================" << endl
             << "Selection: ";
             cin >> response;
        switch (response)
        {
        case 1:
            hexDec(); //convert hex to decimal
            break;
        case 2:
            decHex(); //convert decimal to hex
            break;
        case 3:
            paradox(); //convert to RGB used in paradox games
            break;
        case 9:
            exit(0); //terminate
            break;
        case 0:
            exit(0); //terminate
            break;
        }
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
