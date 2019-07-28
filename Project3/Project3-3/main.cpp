#include <iostream>

using namespace std;

double power(double x, int n) {
	double result = 1;
	while (n > 0) {
		if (n % 2 == 1) result *= x;
		x *= x;
		n /= 2;
	}
	return result;
}

int main(void) {
	cout << power(3, 3) << endl;
}