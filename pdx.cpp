/**
 * @file: pdx.cpp
 * @desc: Converts decimal RGB values (0-255) to values that would work in Paradox Interactive video games.
 * @author: Hermione Maxson
 * @origdate: 27 July 2021 
 * @updated: 29 March 2022 
 * **/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <cstring>

#include "convert.hpp"
#include "bitmap.hpp"
#include "mainMenu.hpp"

using namespace std;
//todo: create conditions for hex or dec conversion

int pdx_quitstate; //quit state
char pdxred[3];
char pdxgreen[3];
char pdxblue[3];
int ry, by, gy = 0;

int pdx_numPrompt(string prompt)
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

bool pdx_inBounds(int floor, int ceiling, int value)
{
    return ((value >= floor) && (value <= ceiling));
}

int pdx_promptInBounds(int floor, int ceiling, string prompt)
{
    int value = floor;
    do
    {
        value = pdx_numPrompt(prompt);
    } while (!pdx_inBounds(floor, ceiling, value));
    return value;
}

void paradox() 
{
    if (strlen(pdxred) == 0) {
        float ry_conv;
        ry = pdx_promptInBounds(0, 255, "Enter a value for red: ");
        cout << "ry:" << ry << endl;
        //need to calculate x/255 here
        cout << "ry_conv:" << ry_conv << endl;
    }
    while (!pdx_quitstate) {
        //null
    }
    return;
}