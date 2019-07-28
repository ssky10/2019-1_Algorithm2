#include <iostream>

using namespace std;

void SecretMap(int n, int* arr1, int* arr2) {
	for (int i = 0; i < n; i++)
	{
		int line = arr1[i] | arr2[i];
		for (int j = n-1; j >= 0; j--) {
			if ((line & (1 << j)) != 0) cout << "#";
			else cout << " ";
		}
		cout << endl;
	}
}

int main(void) {
	int arr1[5] = { 9,20,28,18,11 };
	int arr2[5] = { 30,1,21,17,28 };
	//int *arr1, *arr2;
	//int n;

	//cin >> n;

	//arr1 = new int[n];
	//arr2 = new int[n];

	//for (int i = 0; i < n; i++) cin >> arr1[i];
	//for (int i = 0; i < n; i++) cin >> arr2[i];

	SecretMap(5, arr1, arr2);
	return 0;
}