#include "Command.h"
#include "image.h"
#include <fstream>
#include <iostream>
using namespace std;
 char* Command::Read(const char*filename)
{
	ifstream input;
	input.open(filename, ios::in | ios::binary);
	if (!input)
	{
		return "error";
	}
	char *buffer = new char[20];
	input.getline(buffer, 20);

	input.close();
	return buffer;
}
char* Command::Rename(const char* filename, const char* othername)
{

	size_t len = strlen(filename) + strlen(othername);
	char* newName = new char[len + 1];
	int j = 0;
	int k = 0;
	for (int i = 0; i < len;)
	{
		if (i < strlen(filename) - 4)
		{
			newName[i] = filename[i];
			i++;
			k++;
		}
		else if (j<strlen(othername))
		{
			newName[i] = othername[j];
			j++;
			i++;
		}
		else if (k<strlen(filename))
		{
			newName[i] = filename[k];
			i++;
			k++;
		}

	}
	newName[len] = '\0';
	cout << newName << endl;
	return newName;
}
char* Command::RenameHist(const char* filename, const char* othername)
{
	
	size_t len = strlen(filename) + strlen(othername) - 4;
	char* newName = new char[len + 1];
	int j = 0;
	int k = 0;

	for (int i = 0; i < len;)
	{
		if (i < strlen(filename) - 4)
		{
			newName[i] = filename[i];
			i++;
			k++;
		}
		else if (j<strlen(othername))
		{
			newName[i] = othername[j];
			j++;
			i++;
		}
	}
	newName[len] = '\0';
	cout << newName<<endl;
	return newName;
}
void Command::DoCommands(const char*name, const char * name1, Image * image)
{
	if (!strcmp(name, "--grayscale"))
		image->GrayscaleImage(Rename(name1, "_grayscale"));
	if (!strcmp(name, "--monochrome"))
		image->MonochromeImage(Rename(name1, "_monochrome"));
	if (!strcmp(name, "--histogram=red"))
		image->Histogram(name1, name, RenameHist(name1, "_histogram_red.ppm"), image->Getc(), image->Geth(), image->Getw(), image->GetHistogram(), Read(name1));
	if (!strcmp(name, "--histogram=green"))
		image->Histogram(name1, name, RenameHist(name1, "_histogram_green.ppm"), image->Getc(), image->Geth(), image->Getw(), image->GetHistogram(), Read(name1));
	if (!strcmp(name, "--histogram=blue"))
		image->Histogram(name1, name, RenameHist(name1, "_histogram_blue.ppm"), image->Getc(), image->Geth(), image->Getw(), image->GetHistogram(), Read(name1));
	if (!strcmp(name, "--histogram=rgb"))
		image->Histogram(name1, name, RenameHist(name1, "_histogram_rgb.ppm"), image->Getc(), image->Geth(), image->Getw(), image->GetHistogram(), Read(name1));

}