#pragma once
#include "image.h"
#include "P3.h"
class P5 :public Image
{
private:
	char *magicNumber;
	int h, w, c;
	char* data;
	int* pixels;
	int* histogram;
	int* monochrome;
public:
	P5();
	~P5();

	int Geth()const;
	int Getw()const;
	int Getc()const;
	int *Getpixels()const;
	int *GetHistogram()const;
	int *GetMonochrome()const;

	void ReadImage(const char*filename);
	void GrayscaleImage(const char*filename);
	void MonochromeImage(const char*filename);
	void Histogram(const char*filename, const char *colorname, const char* rename, const char* type);
	
};