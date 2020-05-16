#ifndef BITMAP_H
#define BITMAP_H

/* bitmap generation code sourced from
	https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries. */

const int bpp = 3; //rgb
const int fileHeaderSize = 14;
const int infoHeaderSize = 40;
void generateBitmapImage(unsigned char *image, int height, int width, char *imgFileName);
unsigned char *createBitmapFileHeader(int height, int width, int paddingSize);
unsigned char *createBitmapInfoHeader(int height, int width);

#endif /*BITMAP_H*/