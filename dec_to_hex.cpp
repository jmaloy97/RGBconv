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
#include "convert.hpp"

using namespace std;
int quitstate;

void decHex()
{
    while (!quitstate)
    {
        string colourVal[6];
        int red, green, blue;

        cout << "Red (0-255): ";
        cin >> red;

    /*
        if (red < 0 || red > 255)
        {
            cin.fail();
        }

        else if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Try again.\n > ";
            cin >> red;
        }

        */

       return;
    }
}