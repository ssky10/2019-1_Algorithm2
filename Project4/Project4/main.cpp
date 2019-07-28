#include <iostream>

using namespace std;

double power(double x, int n) {
	if (n == 0) return 1;
	return x * power(x, n - 1);
}

int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}

int fibo(int n) {
	if (n == 0 || n == 1) return 1;
	return fibo(n - 2) + fibo(n - 1);
}

int main() {
	cout << power(2, 3) << endl;
	cout << factorial(3) << endl;
	cout << fibo(4) << endl;
	return 0;
}