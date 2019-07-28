#include <iostream>
#include <algorithm>

#define N 5

using namespace std;

void floyd(int D[N][N]) {
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) {
				if((D[i][k]!=INT_MAX)&&(D[k][j]!=INT_MAX))
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) {
				if (D[i][j] == INT_MAX) cout << "¡Ä" << '\t';
				else cout << D[i][j] << '\t';
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main() {
	int W[N][N] = {
		{0,1,INT_MAX,1,5},
		{9,0,3,2,INT_MAX},
		{INT_MAX,INT_MAX,0,4,INT_MAX},
		{INT_MAX,INT_MAX,2,0,3},
		{3,INT_MAX,INT_MAX,INT_MAX,0}
	};
	floyd(W);
	return 0;
}