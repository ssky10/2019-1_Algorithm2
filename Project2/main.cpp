#include <iostream>

#define LEN 8

using namespace std;

unsigned char readBinary(const char* bitString) {
	unsigned char num=0;
	for (int i = 0; i < LEN; i++)
	{
		num = num << 1;
		num += (bitString[i] - '0');
	}
	return num;
}

int main() {
	cout << (int)readBinary("00000000") << endl;
	cout << (int)readBinary("11111111") << endl;
	cout << (int)readBinary("01010101") << endl;
	cout << (int)readBinary("10000001") << endl;
	return 0;
}