#include <iostream>

#define LEN 8
#define T 16
#define BYTE T/LEN

using namespace std;

unsigned char readBinary(const char* bitString) {
	unsigned char num = 0;
	for (int i = 0; i < LEN; i++)
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
		reversNum += getBit(num, i);
	}
	return reversNum;
}

bool isSymmetry(unsigned char num) {
	for (int i = 0; i < LEN / 2; i++)
	{
		if (getBit(num, i) != getBit(num, LEN - (1 + i))) return false;
	}
	return true;

	//return num == getReversedBits(num);
}

int getHammingDistance(unsigned char* a, unsigned char* b) {
	int count = 0;
	//for (int i = 0; i < LEN; i++) {
	//	for (int j = 0; j < BYTE; j++) {
	//		if (getBit(a[j], i) != getBit(b[j], i)) count++;
	//	}
	//}

	for (int i = 0; i < BYTE; i++) {
		for (unsigned char c = a[i] ^ b[i]; c != 0; c = c & (c - 1)) count++;
		//c - 1의 결과 c의 2진표현상 제일 우측 1은 무조건 0, 그 기준으로 좌측은 유지, 우측은 무조건 1
		//c & (c - 1)의 결과 제일 우측의 1을 0으로 변경 ex:11001110 -> 11001100
	}
	return count;
}

int main() {
	unsigned char a[BYTE], b[BYTE];
	a[0] = readBinary("11111111"); a[1] = readBinary("10000000");
	b[0] = readBinary("00000001"); b[1] = readBinary("00000000");
	cout << getHammingDistance(a,b) << endl;
	return 0;
}