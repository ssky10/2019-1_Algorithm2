#include <iostream>

using namespace std;

int main(void) {
	int** arr;
	int m, n;

	cout << "행의 갯수 입력:";
	cin >> m;
	cout << "열의 갯수 입력:";
	cin >> n;

	arr = new int*[m];

	for (int i = 0; i < m; i++) {
		*(arr+i) = new int[n];
		for (int j = 0; j < n; j++) {
			cout << i + 1 << "행" << j + 1 << "열의 값:";
			cin >> *(*(arr + i) + j); //cin >> arr[i][j];
		}
	}

	cout << "\n----입력된 행렬----" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << *(*(arr + i) + j) << "\t"; //cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}