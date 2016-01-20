#pragma once
#include<fstream>
#include<iostream>
using namespace std;
class Image
{
	
public:
	virtual int Geth()const =0;
	virtual int Getw()const=0;
	virtual int Getc()const=0;
	virtual int * Getpixels()const = 0;
	virtual int * GetHistogram()const = 0;
	virtual void ReadImage(const char*filename) = 0;
	virtual void GrayscaleImage(const char*filename) = 0;
	virtual void MonochromeImage(const char*filename) = 0;
	virtual void Histogram(const char*filename, const char *colorname, const char* rename, int c, int h, int w, int*pixels, const char* type);
	virtual ~Image()
	{

	}
};