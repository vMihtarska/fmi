#include <iostream>
#include <fstream>
#include "P1.h"
using namespace std;

void P1::ReadImage(const char*filename)
{

	ifstream input;
	input.open(filename, ios::in);
	if (!input)
	{
		return;
	}
	stringbuff = new char[100];
	input.getline(stringbuff, 100);
	input.getline(stringbuff, 100);
	input >> w >> h;
	
	int size = h*w;
	pixels = new int[size];
	int* buffer = new int[size];
	int cnt = 0;
	for (int i = 0; i < size; i++)
	{
		input >>pixels[i];
	//	cout << pixels[i] << " ";
		
	}
	input.close();
}
int P1::Geth()const
{
	return h;
}
int P1::Getw()const
{
	return w;
}
int P1::Getc()const
{
	return c;
}
int* P1::Getpixels()const
{
	return pixels;
}
void P1::GrayscaleImage(const char*filename)
{
	return;
}
void P1::MonochromeImage(const char*filename)
{

	return;
}