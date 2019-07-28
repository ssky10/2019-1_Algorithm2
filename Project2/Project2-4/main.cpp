#include <iostream>

#define LEN 8

using namespace std;

unsigned char readBinary(const char* bitString) {
	unsigned char num = bitString[0];
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
	for (int i = LEN - 1; i >= 0; i--) {
		cout << getBit(num, i);
	}
	cout << endl;
}

unsigned char setBitOn(unsigned char num, int i) {
	return num | (1 << i);
}

unsigned char setBitOff(unsigned char num, int i) {
	return num & ~(1 << i);
}

unsigned char updateBit(unsigned char num, int i, bool flag) {
	return flag ? setBitOn(num, i) : setBitOff(num, i);
}

unsigned char getReversedBits(unsigned char num) {
	unsigned char reversNum = 0;
	for (int i = 0; i < LEN; i++)
	{
		reversNum = reversNum << 1;
		reversNum += getBit(num,i);
	}
	return reversNum;
}

int main() {
	printBit(getReversedBits(readBinary("11010101")));
	return 0;
}