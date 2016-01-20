#include <iostream>
#include <fstream>
#include "P2.h"
using namespace std;

P2::P2() :h(0), w(0), c(0)
{
	magicNumber = "";
	pixels = 0;
	histogram = 0;
	monochrome = 0;
}
P2::~P2()
{
	delete[]magicNumber;
	magicNumber = NULL;
	delete[]histogram;
	histogram = NULL;
	delete[]monochrome;
	monochrome = NULL;
	delete[]pixels;
	pixels = NULL;
}
void P2::ReadImage(const char*filename)
{

	ifstream input;
	input.open(filename, ios::in);
	if (!input)
	{
		return;
	}
	magicNumber = new char[100];
	input.getline(magicNumber, 100);
	input >> w >> h >> c;
	if (w == 0 && h == 0 && c == 0)
	{
		input.seekg(0, ios::beg);
		input.clear();
		input.getline(magicNumber, 300);
		input >> w >> h >> c;
	}
	int size = h*w;
	pixels = new int[size];
	histogram = new int[size];
	for (int i = 0; i < size; i++)
	{
		input >> pixels[i];
		histogram[i] = pixels[i];
	}

	input.close();
}
int P2::Geth()const
{
	return h;
}
int P2::Getw()const
{
	return w;
}
int P2::Getc()const
{
	return c;
}
int* P2::Getpixels()const
{
	return pixels;
}
int* P2::GetHistogram()const
{
	return histogram;
}
int* P2::GetMonochrome()const
{
	return monochrome;
}
void P2::GrayscaleImage(const char*filename)
{
	return;
}
void P2::MonochromeImage(const char*filename)
{
	int size = h*w;
	for (int i = 0; i < size; i++)
	{
		if (pixels[i] != 0 && pixels[i] != 255)
			break;
		if (i == size - 1)
			return;
	}

	ofstream output1;
	output1.open(filename, ios::out | ios::binary);
	if (!output1)
	{
		return;
	}
	output1 << "P5" << endl;
	//output1 << "# dfdsfs" << endl;
	output1 << w << " " << h << endl;
	output1 << c << endl;
	
	for (int i = 0; i < size ; i ++)
	{
		if (pixels[i] <= 127)
			pixels[i] = 0;
		else
			pixels[i] = 255;
	}

	for (int i = 0; i < size; i++)
	{

		output1.write((const char*)&pixels[i], sizeof(char));
	}

	output1.close();
}
