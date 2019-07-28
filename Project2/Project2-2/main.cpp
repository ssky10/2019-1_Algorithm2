#include <iostream>

#define LEN 8

using namespace std;

unsigned char readBinary(const char* bitString) {
	unsigned char num = bitString[0] - '0';
	for (int i = 1; i < LEN; i++)
	{
		num = num << 1;
		num += (bitString[i] - '0');
	}
	return num;
}

bool getBit(unsigned char num, int i) {
	//unsigned char mask = 1 << i;
	//if ((num&mask) == 0) return false;
	//else return true;

	return (num & (1 << i)) != 0;
}

void printBit(unsigned char num) {
	for (int i = LEN-1; i >= 0; i--) {
		cout << getBit(num, i);
	}
	cout << endl;
}

int main() {
	cout << getBit(readBinary("10000001"), 7) << endl;
	cout << getBit(readBinary("10000001"), 6) << endl;
	printBit(readBinary("01010101"));
	printBit(readBinary("10000001"));
	return 0;
}