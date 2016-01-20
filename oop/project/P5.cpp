#include <iostream>
#include <fstream>
#include "P5.h"
#include "P2.h"
using namespace std;

P5::P5() :h(0), w(0), c(0)
{
	data = "";
	magicNumber = "";
	pixels = 0;
	histogram = 0;
	monochrome = 0;
}
P5::~P5()
{
	delete[]magicNumber;
	magicNumber = NULL;
	delete[]histogram;
	histogram = NULL;
	delete[]monochrome;
	monochrome = NULL;
	delete[]pixels;
	pixels = NULL;
	delete[]data;
	data = NULL;
}
void P5::ReadImage(const char*filename)
{

	ifstream input;
	input.open(filename, ios::in | ios::binary);
	if (!input)
	{
		cout << "NEEEEEE";
		return;
	}
	magicNumber = new char[100];
	input.getline(magicNumber, 3);
	input >> w >> h >> c;
	if (w == 0 && h == 0 && c == 0)
	{
		input.seekg(0, ios::beg);
		input.clear();
		input.getline(magicNumber, 300);
		input >> w >> h >> c;
	}
	int size = h*w;
	data = new char[size];
	histogram = new int[size];
	input.read(data, size);
	int i = 0;
	pixels = new int[size];
	histogram = new int[size];
	for (int i = 0; i < size; i++)
	{
		if ((int)data[i] < 0)
		{
			histogram[i] = (int)data[i] + 256;
			pixels[i] = (int)data[i] + 256;
		}
		else
		{
			histogram[i] = (int)data[i];
			pixels[i] = (int)data[i];
		}
	}


	input.close();
}
int P5::Geth()const
{
	return h;
}
int P5::Getw()const
{
	return w;
}
int P5::Getc()const
{
	return c;
}
int* P5::Getpixels()const
{
	return pixels;
}
int* P5::GetHistogram()const
{
	return histogram;
}
int* P5::GetMonochrome()const
{
	return monochrome;
}
void P5::GrayscaleImage(const char*filename)
{
	return;
}
void P5::MonochromeImage(const char*filename)
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
	output1 << w << " " << h << endl;
	output1 << c << endl;

	for (int i = 0; i < size; i ++)
	{
		if (pixels[i] <= 127)
			pixels[i] = 0;
		else
			pixels[i] = c;
	}

	for (int i = 0; i<size; i++)
	{
		output1.write((const char*)&pixels[i], sizeof(char));
	}
	output1.close();
}
