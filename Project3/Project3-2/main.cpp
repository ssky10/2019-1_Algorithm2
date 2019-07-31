#include <iostream>

using namespace std;

char num_to_char(int num) {
	if (num < 10) return num + '0';
	else return (num - 10) + 'A';
}

string deci_to_any(int n, int radix) {
	string str = "";
	int i;
	for (i = n; i > 0; i /= radix) {
		str = num_to_char(i%radix) + str;
	}
	//str = num_to_char(i) + str;
	return str;
}

int main(void) {
	cout << "140의 8진법 표기 : " << deci_to_any(140, 8).c_str() << endl;
	cout << "140의 16진법 표기 : " << deci_to_any(140, 16).c_str() << endl;
	return 0;
}