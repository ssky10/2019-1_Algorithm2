#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

//0~(n-1)까지의 숫자를 하나씩 원소로 가지는
//정렬되지 않은 vector 객체를 반환
vector<int> getRandomVector(int n) {
	vector<int> vec;
	for (int i = 0; i < n; i++) vec.push_back(i);
	srand((unsigned int)time(0));
	random_shuffle(vec.begin(), vec.end());
	return vec;
}

void printVector(const vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int partition(int* arr, int len) {
	int* arr2 = new int[len];
	int pivot = arr[0], left = 0, right = len - 1;

	for (int i = 1; i < len; i++) {
		if (arr[i] < pivot) arr2[left++] = arr[i];
		else arr2[right--] = arr[i];
	}
	arr2[left] = pivot;
	for (int i = 0; i < len; i++) arr[i] = arr2[i];
	delete[] arr2;
	return left;
}

int partition2(int* arr, int len) {
	int p = 0, tmp;
	
	for (int i = 1; i < len; i++) {
		if (arr[i] < arr[0]) {
			p++;
			tmp = arr[i];
			arr[i] = arr[p];
			arr[p] = tmp;
		}
	}
	tmp = arr[0];
	arr[0] = arr[p];
	arr[p] = tmp;
	return p;
}

void quickSort(int* arr, int len) {
	if (len < 2) return;
	int p = partition(arr, len);
	quickSort(arr, p);
	quickSort(arr + (p + 1), len - (p + 1));
}

int main(void) {
	vector<int> vec = getRandomVector(100), sorted;
	printVector(vec);
	quickSort(vec.data(), vec.size());
	cout << endl;
	printVector(vec);
}