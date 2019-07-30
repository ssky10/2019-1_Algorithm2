#include <iostream>

using namespace std;
int _count = 0;

int fibonacci_memo(int n, int* memo) {
	_count++;
	if (memo[n] != NULL) return memo[n];
	if (n == 0 || n == 1) return memo[n] = 1;
	/*if (memo[n - 2] != NULL || memo[n - 1] != NULL) {
		if (memo[n - 2] != NULL) {
			if (memo[n - 1] != NULL) return memo[n] = memo[n - 2] + memo[n - 1];
			else return memo[n] = memo[n - 2] + fibonacci_memo(n - 1, memo);
		}
		return memo[n] = fibonacci_memo(n - 2, memo) + memo[n - 1];
	} 	*/
	return memo[n] = fibonacci_memo(n - 2, memo) + fibonacci_memo(n - 1, memo);
}

int main() {
	int* memo;
	int n = 5;
	memo = new int[n + 1];
	memset(memo, NULL, sizeof(int)*(n + 1));
	cout << n << "의 피보나치수 : " << fibonacci_memo(n, memo) << endl;
	//cout << _count << endl;
	delete memo;
	return 0;
}