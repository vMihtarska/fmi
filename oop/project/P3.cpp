#include <iostream>
#include <fstream>
#include "P3.h"
using namespace std;

P3::P3() :h(0), w(0), c(0)
{
	magicNumber = "";
	pixels = 0;
	histogram = 0;
	monochrome = 0;
};
P3::~P3()
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
void P3::ReadImage(const char*filename)
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
	
	int size = h*w * 3;
	pixels = new int[size];
	histogram = new int[size];
	monochrome = new int[size];
	for (int i = 0; i < size; i++)
	{
		input >> pixels[i];
		histogram[i] = pixels[i];
		monochrome[i] = pixels[i];
	}
	input.close();
}
int P3::Geth()const
{
	return h;
}
int P3::Getw()const
{
	return w;
}
int P3::Getc()const
{
	return c;
}
int* P3::Getpixels()const
{
	return pixels;
}
int* P3::GetHistogram()const
{
	return histogram;
}
int* P3::GetMonochrome()const
{
	return monochrome;
}
void P3::GrayscaleImage(const char*filename)
{
	int j = 0;
	int size = h*w * 3;


	while (j < size)
	{
		int sum = pixels[j] + pixels[j + 1] + pixels[j + 2];
		sum /= 3;
		if (pixels[j + 1] != sum && pixels[j + 2] != sum && pixels[j] != sum)
			break;
		j += 3;
		if (j == size - 3)
		{
			return;
		}
	}
	ofstream output;
	output.open(filename, ios::out | ios::binary);
	if (!output)
	{
		return;
	}
	output << "P6" << endl;
	output << w << " " << h << endl;
	output << c << endl;
	int i = 0;
	while (i < size)
	{
		int sum = pixels[i] + pixels[i + 1] + pixels[i + 2];
		sum /= 3;
		pixels[i + 1] = pixels[i + 2] = pixels[i] = sum;
		i += 3;
	}
	
	for (int i = 0; i<size; i++)
	{
		output.write((const char*)&pixels[i], sizeof(char));
	}

	output.close();
}
void P3::MonochromeImage(const char*filename)
{
	int size = h*w * 3;
	int i = 0;
	int sum = 0;
	
	for (int i = 0; i < size; i += 3)
	{

		if ((monochrome[i] != 0 && monochrome[i + 1] != 0 && monochrome[i + 2] != 0) &&
			(monochrome[i] != 255 && monochrome[i + 1] != 255 && monochrome[i + 2] != 255))
			break;
		if (i == size - 3)
			return;
	}
	ofstream output1;
	output1.open(filename, ios::out | ios::binary);
	if (!output1)
	{
		return;
	}
	output1 << "P6" << endl;
	output1 << w << " " << h << endl;
	output1 << c << endl;
	
	while (i < size)
	{
		int sum = monochrome[i] + monochrome[i + 1] + monochrome[i + 2];
		sum /= 3;
		monochrome[i + 1] = monochrome[i + 2] = monochrome[i] = sum;
		i += 3;
	}

	for (int i = 0; i < size; i += 3)
	{
		if (monochrome[i] <= 127)
			monochrome[i] = monochrome[i + 1] = monochrome[i + 2] = 0;
		else
			monochrome[i] =monochrome[i + 1] = monochrome[i + 2] = 255;
	}

	for (int i = 0; i < size; i++)
	{

		output1.write((const char*)&monochrome[i], sizeof(char));
	}

	output1.close();
}