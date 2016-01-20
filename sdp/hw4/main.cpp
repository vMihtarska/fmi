#include <iostream>
#include "Vector.h"
#include "Tree.h"
#include "ReadInput.h"

int main(int argc,char** argv)
{
	/*char* b = "(1{(2{(5{})(6{(10{})})})(3{(7{})})(4{(8{(11{})(12{})})(9{})})})";
	ReadInput a;
	a.MakeATree(b);
	
	char* b1 = " (1{(2{(5{(10{})(11{})})(6{})})(3{(7{})(8{(12{(13{})})})})(4{(9{})})})";
	ReadInput a1;
	a1.MakeATree(b1);

	if (a.getTree()->isIsomorphism(*a1.getTree()))
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}*/
	ReadInput* trees = new ReadInput[2];
	int j = 0;
	for (int i = 1; i < argc; i++)
		trees[j++].MakeATree(argv[i]);
	
	if (trees[0].getTree()->isIsomorphism(*trees[1].getTree()))
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}
}