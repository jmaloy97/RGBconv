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

#include "convert.hpp"
#include "bitmap.hpp"
#include "mainMenu.hpp"

using namespace std;

//numeric_limits<unsigned char> constraints;

int quitstate;
char red[3];
char green[3];
char blue[3];
int rx, bx, gx;

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
    while (!quitstate)
    {
        if (strlen(red) == 0)
        {
            rx = promptInBounds(0, 255, "Enter a value for red: ");
            sprintf(red, paddedHexFormat, rx);
        }
        else if (strlen(green) == 0)
        {
            gx = promptInBounds(0, 255, "Enter a value for green: ");
            sprintf(green, paddedHexFormat, gx);
        }
        else if (strlen(blue) == 0)
        {
            bx = promptInBounds(0, 255, "Enter a value for blue: ");
            //cout << bx << endl;
            sprintf(blue, paddedHexFormat, bx);
        }
        else
        {
            cout << "\nHexadecimal RGB value: #" << red << green << blue << endl;
            char startOver;

            int height = 500;
            int width = 500;
            unsigned char image[height][width][bpp];
            char *imageFileName = "output.bmp";

            /* cout << "rx: " << rx
                 << "\ngx: " << gx
                 << "\nbx: " << bx << endl; */

            int i, j;
            for (i = 0; i < height; i++)
            {
                for (j = 0; j < width; j++)
                {
                    image[i][j][2] = rx; ///red
                    image[i][j][1] = gx; ///green
                    image[i][j][0] = bx; ///blue
                }
            }

            generateBitmapImage((unsigned char *)image, height, width, imageFileName);
            printf("\nImage generated: ");
            cout << imageFileName << endl;

            cout << "\nStart over (Y/N)? ";
            cin >> startOver;

            if (startOver == 'Y' || startOver == 'y')
            {
                printf("\n");
                memset(red, 0, sizeof(red));
                memset(green, 0, sizeof(green));
                memset(blue, 0, sizeof(blue));
            }

            else
            {
                return;
            }
        }
    }
}
