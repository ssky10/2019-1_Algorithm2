#include <iostream>

using namespace std;

int fibo_dp(int n, int* memo) {
	if (n == 0 || n == 1) return 1;
	memo[0] = 0; memo[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		memo[i] = memo[i - 1] + memo[i - 2];
	}
	return memo[n];
}

int main() {
	int *memo;
	int n = 5;
	memo = new int[n + 1];
	cout << fibo_dp(n,memo);
	return 0;
}