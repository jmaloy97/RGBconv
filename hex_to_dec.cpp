/**
 *
 *	@file: hex_to_dec.cpp
 *	@desc: Converts a hexadecimal RGB value into decimal form.
 *	@author: Hermione M.
 *	@date: 15 May 2020
 *
 *	This file is licensed under the BSD License: enter requisite licensing bullshit here.
 *
 */

using namespace std;
int exitstate;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>

#include "convert.hpp"
#include "bitmap.hpp"
#include "mainMenu.hpp"

void hexDec()
{
	while (!exitstate)
	{
		//cout << "Testing to make sure I haven't gone senile.\n";

		string colourVal[6];
		string a;

		cout << "Please enter a valid hexadecimal colour value: ";
		cin >> a;
		printf("\n");
		if (a.size() <= 5 || a.size() >= 7)
		{
			cout << "FATAL ERROR: Invalid hexidecimal colour code." << endl;
			return;
		}

		for (int i = 0; i < a.size(); i++)
		{
			// cout << a[i] << endl;
			char testing_char = a[i];
			int ascii = (int)testing_char;
			//cout << "i: " << i << " - " << testing_char << ": " << ascii << endl;
			if ((ascii >= 97) && (ascii <= 102))
			{
				//cout << "Lower-case hexadecimal character." << endl;
				testing_char = toupper(testing_char);
				colourVal[i] = testing_char;
			}
			else if ((ascii >= 48) && (ascii <= 57))
			{
				//cout << "You've passed me a number." << endl;
				colourVal[i] = testing_char;
			}
			else if ((ascii >= 65) && (ascii <= 70))
			{
				//cout << "Uppercase hexadecimal value." << endl;
				colourVal[i] = testing_char;
			}
			else
			{
				printf("Invalid character found, returning to main menu...\n\n");
				return;
			}
		}

		string r_val = colourVal[0] + colourVal[1];
		string g_val = colourVal[2] + colourVal[3];
		string b_val = colourVal[4] + colourVal[5];
		//	cout << r_val << endl << g_val << endl << b_val << endl;
		int red, green, blue;
		red = stoi(r_val, 0, 16);
		green = stoi(g_val, 0, 16);
		blue = stoi(b_val, 0, 16);

		cout << "Hex -> RGB value conversion:\n";
		cout << "Red: " << red << endl;
		cout << "Green: " << green << endl;
		cout << "Blue: " << blue << endl;

		int height = 500;
		int width = 500;
		unsigned char image[height][width][bpp];
		char *imageFileName = "output.bmp";

		int i, j;
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				image[i][j][2] = red;	///red
				image[i][j][1] = green; ///green
				image[i][j][0] = blue;	///blue
			}
		}

		generateBitmapImage((unsigned char *)image, height, width, imageFileName);
		printf("\nImage generated: ");
		cout << imageFileName << endl;

		char startOver;

		cout << "\nStart over (Y/N)? ";
		cin >> startOver;

		if (startOver == 'Y' || startOver == 'y')
		{
			printf("\n");
		}

		else
		{
			return;
		}
	}
}
