#pragma once
#include "image.h"
class P2 :public Image
{
private:
	char *magicNumber;
	int h, w,c;
	int* pixels;
	int* histogram;
	int* monochrome;
public:
	P2();
	~P2();

	int Geth()const;
	int Getw()const;
	int Getc()const;
	int *Getpixels()const;
	int *GetHistogram()const;
	int *GetMonochrome()const;

	void ReadImage(const char*filename);
	void GrayscaleImage(const char*filename);
	void MonochromeImage(const char*filename);
	void Histogram(const char*filename, const char *colorname, const char*rename, const char* type);
};