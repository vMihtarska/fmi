
#include <iostream>
#include <cmath>

int countDigits(int n) {
	int count = 0;
	while (n > 0) {
		n = n / 10;
		count++;
	}

	return count;
}

void automorphicNumbers() {
	int n;
	cout << "Enter a number: ";
	cin >> n;
	
	int divisor = 0;
	for (int i = 1; i < n; i++) {
		divisor = pow(10, countDigits(i));
		if ( ((i * i) % divisor) == i)
			std::cout << i << "\n";
	}
}

using namespace std;
int main()
{
   automorphicNumbers();
   return 0;
}

