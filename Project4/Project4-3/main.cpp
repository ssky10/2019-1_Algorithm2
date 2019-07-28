#include <iostream>

using namespace std;
int _count = 0;

int combination(int n, int r) {
	//_count++;
	if (r == 0 || n == r) return 1;
	return combination(n - 1, r - 1) + combination(n - 1, r);
}

int combination_memo(int n, int r, int** memo) {
	_count++;
	if (memo[n][r] != NULL) return memo[n][r];
	if (r == 0 || n == r) return memo[n][r] = 1;
	/*if (memo[n-1][r-1] != NULL || memo[n - 1][r] != NULL) {
		if (memo[n-1][r-1] != NULL) {
			if (memo[n - 1][r] != NULL) return memo[n][r] = memo[n - 1][r - 1] + memo[n - 1][r];
			else return memo[n][r] = memo[n - 1][r - 1] + combination_memo(n - 1, r, memo);
		}
		return memo[n][r] = combination_memo(n - 1, r - 1, memo) + memo[n - 1][r];
	}*/
	return memo[n][r] = combination_memo(n - 1, r - 1, memo) + combination_memo(n - 1, r, memo);
}

int main() {
	int** memo;
	int n = 5;
	int r = 2;
	memo = new int*[n + 1];
	for (int i = 0; i <= n; i++) {
		memo[i] = new int[r + 1];
		memset(memo[i], NULL, sizeof(int)*(r + 1));
	}
	cout << combination(n, r) << endl;
	cout << combination_memo(n, r, memo) << endl;
	cout << _count << endl;
	for (int i = 0; i <= n; i++) delete[] memo[i];
	delete[] memo;
	return 0;
}