/**
 *
 *	@file: dec_to_hex.cpp
 *	@desc: Converts a decimal RGB value into hex form.
 *	@author: Hermione M.
 *	@date: 16 May 2020
 *
 *	This file is licensed under the BSD License: enter requisite licensing bullshit here.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <cstring>

using namespace std;

long long int value;
int quitstate;
char red[2];
char green[2];
char blue[2];

void decHex()
{
    while (!quitstate)
    {
        if (strlen(red) == 0)
        {
            cout << "Enter a value for red: ";
            cin >> value;
            if (value < 0 || value > 255)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            else if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            else
            {
                sprintf(red, "%X", value);
                cout << "red    " << red << endl;
                
            }
        }

        else if (strlen(green) == 0)
        {
            cout << "Enter a value for green: ";
            cin >> value;
            if (value < 0 || value > 255)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            else if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            else
            {
                sprintf(green, "%X", value);
                cout << "green    " << green << endl;
                
            }
        }

        else if (strlen(blue) == 0)
        {
            cout << "Enter a value for blue: ";
            cin >> value;
            if (value < 0 || value > 255)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            else if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            else
            {
                sprintf(blue, "%X", value);
                cout << "blue    " << blue << endl;
            }
        }

        else {
            cout << red << endl;
            cout << green << endl;
            cout << blue << endl;
            memset(red, 0, 255);
            memset(green, 0, 255);
            memset(blue, 0, 255);
            return;
        }
    }
}