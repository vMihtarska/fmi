//Василка Михтарска ФН:45053 
#include<iostream>
#include<fstream>
#include "image.h"
#include "Command.h"
#include "P6.h"
#include "P3.h"
#include "P2.h"
#include "P5.h"
#include "P1.h"
using namespace std;


int main(int argc,char* argv[])
{
Image**s=new Image*[10];
int cnt = 0;
for (int i = 0; i < argc; i++)
	cout << argv[i] << endl;
for (int i = 1; i < argc; i++)
{
	
	if (!strcmp(Command::Read(argv[i]), "P3"))
	{
		s[cnt] = new P3;
		s[cnt]->ReadImage(argv[i]);

		for (int j = 1; j<argc; j++)
		{
			Command::DoCommands(argv[j], argv[i], s[cnt]);
		}
		cnt++;
	
	}
	if (!strcmp(Command::Read(argv[i]), "P6"))
	{	s[cnt] = new P6;
		s[cnt]->ReadImage(argv[i]);
		for (int j = 1; j<argc; j++)
		{
			Command::DoCommands(argv[j], argv[i], s[cnt]);
		}
		cnt++;
	}
	if (!strcmp(Command::Read(argv[i]), "P2"))
	{
		s[cnt] = new P2;
		s[cnt]->ReadImage(argv[i]);
		for (int j = 1; j<argc; j++)
		{
			Command::DoCommands(argv[j], argv[i], s[cnt]);
		}
		cnt++;
	}
	//if (!strcmp(Read(argv[i]), "P1"))
	//{	s[cnt] = new P1;
	//	s[cnt]->ReadImage(argv[i]);
	//	for(int j=1;j<argc;j++)
	//	{
	//		//if(!strcmp(argv[j],"--Histogram"))
	//		//s[cnt]->Histogram();
	//	}
	//	cnt++;
	//}
	//if (!strcmp(Read(argv[i]), "P4"))
	//{
	//	s[cnt] = new P4;
	//	s[cnt]->ReadImage(argv[i]);
	//	for(int j=1;j<argc;j++)
	//	{
	//		DoCommands(argv[j], argv[i], s[cnt]);
	//	}
	//	cnt++;
	//}
	if (!strcmp(Command::Read(argv[i]), "P5"))
	{	s[cnt] = new P5;
		s[cnt]->ReadImage(argv[i]);
		for(int j=1;j<argc;j++)
		{
			Command::DoCommands(argv[j], argv[i], s[cnt]);
		}
		cnt++;
	}
	
}

}

