#include <iostream>

using namespace std;

void swap(int*a, int*b) {
	*a = *a - *b; //*a = *a^*b
	*b = *a + *b; //*b = *a^*b
	*a = *b - *a; //*a = *a^*b
}

int main(void) {
	int a = 1, b = 5;
	cout << "before : " << a << ", " << b << endl;
	swap(a, b);
	cout << "after : " << a << ", " << b << endl;
}