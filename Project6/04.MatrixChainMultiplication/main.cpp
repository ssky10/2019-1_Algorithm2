#include <iostream>
#include <algorithm>

#define N 5

using namespace std;

void order(int i, int j, int K[][N + 1]) {
	if (i == j)cout << "A" << i;
	else {
		int k = K[i][j];
		cout << "(";
		order(i, k, K);
		order(k + 1, j, K);
		cout << ")";
	}
}

int mcm(int *d) {
	int M[N + 1][N + 1];
	int K[N + 1][N + 1];

	for (int i = 1; i <= N; i++) M[i][i] = 0;

	for (int len = 2; len <= N; len++) {
		for (int i = 1; i <= N - len + 1; i++) {
			int j = i + len - 1;
			M[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				int cost = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (cost < M[i][j]) {
					M[i][j] = cost;
					K[i][j] = k;
				}
			}
		}
	}
	order(1, N, K);
	return M[1][N];
}

int main() {
	int d[N + 1] = { 5,2,3,4,5,7 };
	cout << mcm(d) << endl;
	return 0;
}