
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	double x, y;
	cout << "x,y=";
	cin >> x >> y;
	double r = 2;
	double R = 1;
	bool inCircle = x*x + y*y < r*r;
	bool onCircle = (x*x + y*y == r*r);
	bool inSq = fabs(x) < R && fabs(y) < r;
	bool outSq = fabs(x) > R || fabs(y) > r;
	bool onSq = !inSq&&!outSq;
	if (x == 0 && y == 0)
	{
		cout << "The point is in the gray part of the figure."<<endl;
	}
	
	else if (y>0 && inCircle)
		{
			cout << "The point is in the gray part of the figure."<<endl;
		}
	else if (y > 0 && onCircle)
		{ 
			cout << "The point is on the loop"<<endl;
		}
	else if (y < 0 && inSq)
		{
			cout << "The point is in the gray part of the figure."<<endl;
		}
	else if (y < 0 && onSq)
		{
			cout << "The point is on the loop"<<endl;
		}
	
	else cout << "The point is'nt in the gray part of the figure."<<endl;
	

	return 0;


}
