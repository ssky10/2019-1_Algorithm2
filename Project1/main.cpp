#include <iostream>

using namespace std;

int main(void) {
	int** arr;
	int m, n;

	cout << "���� ���� �Է�:";
	cin >> m;
	cout << "���� ���� �Է�:";
	cin >> n;

	arr = new int*[m];

	for (int i = 0; i < m; i++) {
		*(arr+i) = new int[n];
		for (int j = 0; j < n; j++) {
			cout << i + 1 << "��" << j + 1 << "���� ��:";
			cin >> *(*(arr + i) + j); //cin >> arr[i][j];
		}
	}

	cout << "\n----�Էµ� ���----" << endl;
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