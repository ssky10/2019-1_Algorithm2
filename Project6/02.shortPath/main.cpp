#include <iostream>

using namespace std;

int shortpath_dp(int n, int** map, int** path) {
	path[0][0] = path[0][0];
	for (int i = 1; i < n; i++) {
		path[0][i] = path[0][i-1];
		path[i][0] = path[i-1][0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++)
		{
			path[i][j] = path[i - 1][j] + path[i][j - 1];
		}
	}
	return path[n-1][n-1];
}

int main() {
	int map[5][5] = {
		{1,1,1,1,1},
		{1,1,0,0,1},
		{1,1,1,1,1},
		{1,1,1,0,1},
		{0,0,1,1,1},
	};
	int **path;
	int n = 5;
	path = new int*[n];
	for (int i = 0; i < n; i++) {
		path[i] = new int[n];
	}
	//cout << shortpath_dp(n, map, path);
	return 0;
}