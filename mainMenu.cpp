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

void mainMenu()
{
    int response = 0;
    while (true)
    {
        cout << "====== RGB Converter ========" << endl
             << "1. Convert Hex to Decimal" << endl
             << "2. Convert Decimal to Hex" << endl
             << "9. Exit" << endl
             << "=============================" << endl
             << "Selection: ";
             cin >> response;
        switch (response)
        {
        case 1:
            hexDec(); //convert hex to decimal
            break;
        case 2:
            printf("\nUnimplemented! Sorry about that!\n");
            decHex(); //convert decimal to hex
            break;
        case 9:
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
