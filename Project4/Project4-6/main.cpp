#include <iostream>

using namespace std;
int _count = 0;

bool check(int row, int col, int* map) {
	if (row == 0) return true;
	for (int i = 0; i < row; i++)
	{
		if (map[i] == col) return false;

		//if ((row - col) == (i - map[i])) return false;
		//if ((row + col) == (i + map[i])) return false;

		//int colDistance = abs(map[i] - col);
		//int rowDistance = abs(i - row);
		//if (colDistance == rowDistance) return false;

		if ((map[i] == (col - row + i)) || (map[i] == (col + row - i))) return false;
	}
	return true;
}

int nQueen(int row, int n, int* map) {
	_count++;
	if (row == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << ((map[i] == j) ? ("г╤") : ("бр"));
			cout << endl;
		}
			
		cout << endl;
		return  1;
	}
	int ways = 0;
	for (int col = 0; col < n; col++)
	{
		if (check(row, col, map)) {
			map[row] = col;
			ways += nQueen(row + 1, n, map);
			//map[row] = -1;
		}
	}

	return ways;
}

int main() {
	int *map;
	int n = 4;
	map = new int[n];
	//memset(map, -1, sizeof(int)*n);
	cout << nQueen(0, n, map) << " / ";
	cout << _count << endl;
	return 0;
}