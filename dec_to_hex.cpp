/**
 *
 *	@file: dec_to_hex.cpp
 *	@desc: Converts a decimal RGB value into hex form.
 *
 *	@authors: Hermione M.
 *            Jeremy B.
 * 
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

int quitstate;
char red[3];
char green[3];
char blue[3];

const char *paddedHexFormat = "%02X";

int numPrompt(string prompt)
{
    int val;
    do
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << prompt;
        cin >> val;
    } while (cin.fail());
    return val;
}

bool inBounds(int floor, int ceiling, int value)
{
    return ((value >= floor) && (value <= ceiling));
}

int promptInBounds(int floor, int ceiling, string prompt)
{
    int value = floor;
    do
    {
        value = numPrompt(prompt);
    } while (!inBounds(floor, ceiling, value));
    return value;
}

void decHex()
{
    int value;
    numeric_limits<unsigned char> constaints;
    while (!quitstate)
    {
        if (strlen(red) == 0)
            sprintf(red, paddedHexFormat, promptInBounds(constaints.min(), constaints.max(), "Enter a value for red: "));
        else if (strlen(green) == 0)
            sprintf(green, paddedHexFormat, promptInBounds(constaints.min(), constaints.max(), "Enter a value for green: "));
        else if (strlen(blue) == 0)
            sprintf(blue, paddedHexFormat, promptInBounds(constaints.min(), constaints.max(), "Enter a value for blue: "));
        else
        {
            cout << red << green << blue << endl;
            return;
        }
    }
}
