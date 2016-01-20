#include "image.h"
void Image::Histogram(const char*filename, const char *colorname, const char* rename, int c, int h, int w, int*pixels, const char* type)
{
	ofstream output1;
	int wh = 256;
	int hh = 100;
	output1.open(rename, ios::out | ios::binary);
	if (!output1)
	{
		return;
	}
	output1 << "P6" << endl;
	output1 << wh << " " << hh << endl;
	output1 << c << endl;
	int colors[256];
	int colors1[256];
	int colors2[256];
	int colors3[256];
	for (int i = 0; i < 256; i++)
	{
		colors[i] = 0;
		colors1[i] = 0;
		colors2[i] = 0;
		colors3[i] = 0;
	}
	int** temp = new int*[hh];
	for (int i = 0; i < hh; i++)
		temp[i] = new int[wh * 3];
	//cout << h << w;
	int size = h*w;

	
	if (strcmp(type, "P6") == 0 || strcmp(type, "P3") == 0)
	{
		size *= 3;
	
		for (int i = 0; i < 256; i++)
		{
			if (strcmp(colorname, "--histogram=rgb") == 0)
			{
				for (int j = 2; j < size; j += 3)
				if (pixels[j] == i)
					colors1[i]++;
				for (int j = 0; j < size; j += 3)
				if (pixels[j] == i)
					colors2[i]++;
				for (int j = 1; j < size; j += 3)
				if (pixels[j] == i)
					colors3[i]++;
			}
			if (strcmp(colorname, "--histogram=blue") == 0)
			{
				for (int j = 2; j < size; j += 3)
				if (pixels[j] == i)
					colors[i]++;
			}
			else if (strcmp(colorname, "--histogram=red") == 0)
			{
				for (int j = 0; j < size; j += 3)
				if (pixels[j] == i)
					colors[i]++;
			}
			else if (strcmp(colorname, "--histogram=green") == 0)
			{
				for (int j = 1; j < size; j += 3)
				if (pixels[j] == i)
					colors[i]++;
			}

		}

	}
	else
	{
		for (int i = 0; i < 256; i++)
		{
			for (int j = 0; j < size; j++)
			if (pixels[j] == i)
				colors[i]++;
		}
	}
	
	for (int i = 0; i < 256; i++)
		colors[i] = (colors[i] * 10000) / (h*w);
	if (strcmp(colorname, "--histogram=rgb") == 0 && (strcmp(type, "P6") == 0 || strcmp(type, "P3") == 0))
	{
		for (int i = 0; i < 256; i++)
			colors1[i] = (colors1[i] * 10000) / (h*w);
		for (int i = 0; i < 256; i++)
			colors2[i] = (colors2[i] * 10000) / (h*w);
		for (int i = 0; i < 256; i++)
			colors3[i] = (colors3[i] * 10000) / (h*w);

		
		for (int i = 0; i < hh; i++)
		{
			for (int j = 0, k = 0; j < wh, k < wh; j += 3, k++)
			{
				if (i >= (99 - colors1[k]))
				{
					temp[i][j] = 0;
					temp[i][j + 1] = 0;
					temp[i][j + 2] = 255;
				}
				else
				if (i >= (99 - colors2[k]))
				{

					temp[i][j] = 255;
					temp[i][j + 1] = 0;
					temp[i][j + 2] = 0;


				}
				else
				if (i >= (99 - colors3[k]))
				{
					temp[i][j] = 0;
					temp[i][j + 1] = 255;
					temp[i][j + 2] = 0;
				}
				else
				{
					temp[i][j] = 255;
					temp[i][j + 1] = 255;
					temp[i][j + 2] = 255;

				}
			}
		}
	}
	else
	{

		for (int i = 0; i < hh; i++)
		{
			for (int j = 0, k = 0; j < wh, k < wh; j += 3, k++)
			{
				if (i >= (99 - colors[k]))
				{
					if (strcmp(colorname, "--histogram=blue") == 0)
					{
						temp[i][j] = 0;
						temp[i][j + 1] = 0;
						temp[i][j + 2] = 255;
					}
					else if (strcmp(colorname, "--histogram=red") == 0)
					{
						temp[i][j] = 255;
						temp[i][j + 1] = 0;
						temp[i][j + 2] = 0;
					}
					else if (strcmp(colorname, "--histogram=green") == 0)
					{
						temp[i][j] = 0;
						temp[i][j + 1] = 255;
						temp[i][j + 2] = 0;
					}
				}
				else temp[i][j] = temp[i][j + 1] = temp[i][j + 2] = 255;

			}
		}
	}
	
	for (int i = 0; i < hh; i++)
	{
		for (int j = 0; j < wh* 3; j++)
		{
			output1.write((const char*)&temp[i][j], sizeof(char));
		}
	}
	if (temp != NULL)
	{
		for (int i = 0; i < hh; i++)
			delete[]temp[i];
		delete[] temp;
		temp = NULL;
	}
	output1.close();

}