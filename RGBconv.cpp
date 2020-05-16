/**
 *
 *	@file: RGBconv.cpp
 *	@desc: Converts a hexadecimal RGB value into decimal form.
 *	@author: Hermione M.
 *	@date: 15 May 2020
 *
 *	This file is licensed under the BSD License: enter requisite licensing bullshit here.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iterator>

using namespace std;

/* code in this section is sourced from
	https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries. */
const int bpp = 3; //rgb
const int fileHeaderSize = 14;
const int infoHeaderSize = 40;
int exitstate;
void generateBitmapImage(unsigned char *image, int height, int width, char *imgFileName);
unsigned char *createBitmapFileHeader(int height, int width, int paddingSize);
unsigned char *createBitmapInfoHeader(int height, int width);
/* end section */

int main()
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
			return 0;
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
				printf("Invalid character!\n");
				exit(0);
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
			return 0;
		}
	}
}

/* bitmap generation code sourced from
	https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries. */
void generateBitmapImage(unsigned char *image, int height, int width, char *imageFileName)
{

	unsigned char padding[3] = {0, 0, 0};
	int paddingSize = (4 - (width * bpp) % 4) % 4;

	unsigned char *fileHeader = createBitmapFileHeader(height, width, paddingSize);
	unsigned char *infoHeader = createBitmapInfoHeader(height, width);

	FILE *imageFile = fopen(imageFileName, "wb");

	fwrite(fileHeader, 1, fileHeaderSize, imageFile);
	fwrite(infoHeader, 1, infoHeaderSize, imageFile);

	int i;
	for (i = 0; i < height; i++)
	{
		fwrite(image + (i * width * bpp), bpp, width, imageFile);
		fwrite(padding, 1, paddingSize, imageFile);
	}

	fclose(imageFile);
}

unsigned char *createBitmapFileHeader(int height, int width, int paddingSize)
{
	int fileSize = fileHeaderSize + infoHeaderSize + (bpp * width + paddingSize) * height;

	static unsigned char fileHeader[] = {
		0, 0,		/// signature
		0, 0, 0, 0, /// image file size in bytes
		0, 0, 0, 0, /// reserved
		0, 0, 0, 0, /// start of pixel array
	};

	fileHeader[0] = (unsigned char)('B');
	fileHeader[1] = (unsigned char)('M');
	fileHeader[2] = (unsigned char)(fileSize);
	fileHeader[3] = (unsigned char)(fileSize >> 8);
	fileHeader[4] = (unsigned char)(fileSize >> 16);
	fileHeader[5] = (unsigned char)(fileSize >> 24);
	fileHeader[10] = (unsigned char)(fileHeaderSize + infoHeaderSize);

	return fileHeader;
}

unsigned char *createBitmapInfoHeader(int height, int width)
{
	static unsigned char infoHeader[] = {
		0, 0, 0, 0, /// header size
		0, 0, 0, 0, /// image width
		0, 0, 0, 0, /// image height
		0, 0,		/// number of color planes
		0, 0,		/// bits per pixel
		0, 0, 0, 0, /// compression
		0, 0, 0, 0, /// image size
		0, 0, 0, 0, /// horizontal resolution
		0, 0, 0, 0, /// vertical resolution
		0, 0, 0, 0, /// colors in color table
		0, 0, 0, 0, /// important color count
	};

	infoHeader[0] = (unsigned char)(infoHeaderSize);
	infoHeader[4] = (unsigned char)(width);
	infoHeader[5] = (unsigned char)(width >> 8);
	infoHeader[6] = (unsigned char)(width >> 16);
	infoHeader[7] = (unsigned char)(width >> 24);
	infoHeader[8] = (unsigned char)(height);
	infoHeader[9] = (unsigned char)(height >> 8);
	infoHeader[10] = (unsigned char)(height >> 16);
	infoHeader[11] = (unsigned char)(height >> 24);
	infoHeader[12] = (unsigned char)(1);
	infoHeader[14] = (unsigned char)(bpp * 8);

	return infoHeader;
}
/* end section */
