#include <iostream>

using namespace std;
int _count = 0;
int _countM = 0;

int step(int n) {
	_count++;
	if (n < 0) return 0;
	if (n == 0) return 1;
	return step(n - 1) + step(n - 2) + step(n - 3);
}

int step_memo(int n, int* memo) {
	_countM++;
	if (n < 0) return 0;
	if (memo[n] != NULL) return memo[n];
	if (n == 0) return memo[n] = 1;
	return memo[n] = step_memo(n - 1, memo) + step_memo(n - 2, memo) + step_memo(n - 3, memo);
}

int main() {
	int* memo;
	int n = 10;
	memo = new int[n+1];
	memset(memo, NULL, sizeof(int)*(n+1));
	cout << step(n) << endl;
	cout << step_memo(n, memo) << endl;
	cout << "ÀÏ¹İ Àç±Í ¹æ½Ä Àç±ÍÈ£Ãâ ¼ö : " << _count << endl;
	cout << "Memoization Àç±Í ¹æ½Ä Àç±ÍÈ£Ãâ ¼ö : " << _countM << endl;
	delete memo;
	return 0;
}