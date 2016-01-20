#pragma once
#include "image.h"
class P1 :public Image
{
private:
	char*stringbuff;
	int h, w,c;
	int* pixels;
	int*histogram;
	int*monochrome;
	
public:
	P1() :h(0), w(0), c(0)
	{
		stringbuff = "";
		pixels = 0;
		histogram = 0;
		monochrome = 0;
	};
	int Geth()const;
	int Getw()const;
	int Getc()const;
	int *Getpixels()const;
	int *GetHistogram()const
	{
		return histogram;
	}
	int *GetMonochrome()const
	{
		return monochrome;
	}

	void ReadImage(const char*filename);
	void GrayscaleImage(const char*filename);
	void MonochromeImage(const char*filename);
	void Histogram(const char*filename, const char *colorname, const char* rename, const char* type)
	{}
};