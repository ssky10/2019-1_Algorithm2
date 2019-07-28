#include <iostream>

using namespace std;
int _count = 0;

int step(int n) {
	//_count++;
	if (n < 0) return 0;
	if (n == 0) return 1;
	return step(n - 1) + step(n - 2) + step(n - 3);
}

int step_memo(int n, int* memo) {
	_count++;
	if (n < 1) return 0;
	if (memo[n - 1] != NULL) return memo[n - 1];
	if (n == 1) return memo[n - 1] = 1;
	return memo[n - 1] = step(n - 1) + step(n - 2) + step(n - 3);
}

int main() {
	int* memo;
	int n = 10;
	memo = new int[n];
	memset(memo, NULL, sizeof(int)*n);
	cout << step(n) << endl;
	cout << step_memo(n, memo) << endl;
	cout << _count << endl;
	delete memo;
	return 0;
}