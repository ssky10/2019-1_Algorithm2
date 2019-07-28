#include <iostream>

using namespace std;

void print_real(int n, int d, int k) {
	cout << n / d << ".";
	for (int i = 0; i < k; i++)
	{
		n = (n%d) * 10;
		cout << n / d;
	}
	cout << endl;
}

int main(void) {
	print_real(9, 7, 10);
	return 0;
}