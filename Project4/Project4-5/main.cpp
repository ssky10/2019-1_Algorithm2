#include <iostream>

using namespace std;
//int _count = 0;

int coin[] = { 500,100,50,10,1 };
//500,100,50,10,1
int chage(int n,int max_coin) {
	//_count++;
	if (max_coin == 4) return 1;

	int result = 0;
	for (int i = 0; i <= n / coin[max_coin]; i++)
	{
		result += chage(n - (coin[max_coin] * i), max_coin + 1);
	}
	
	return result;
}

int main() {
	int n = 62;
	cout << n << "원을 거슬러 줄 수 있는 경우의 수 : " << chage(n, 0) << endl;
	//cout << _count << endl;
	return 0;
}