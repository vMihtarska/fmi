#pragma once
#include "image.h"
class Command:public Image
{
public:
	static char* Read(const char*filename);
	static char* Rename(const char* filename, const char* othername);
	static char* RenameHist(const char* filename, const char* othername);
	static void DoCommands(const char*name, const char * name1, Image * image);


};