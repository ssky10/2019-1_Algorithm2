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

//0~(k-1)까지의 정수를 n개 가지는 벡터생성
vector<int> getRandomVector(int k, int n) {
	vector<int> vec;
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++) vec.push_back(rand() % k);
	return vec;
}

void printVector(const vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

void radixSort(int* arr, int len, int d) {
	for (int i = 0, mod=10; i < d; i++, mod*=10) {
		vector<int> buckets[10];
		for (int j = 0; j < len; j++)
		{
			buckets[(arr[j] % mod) / (mod / 10)].push_back(arr[j]);
		}

		for (int j = 0, size, idx = 0; j < 10; j++, idx += size)
		{
			if (size = buckets[j].size()) {
				memcpy(arr + idx, buckets[j].data(), sizeof(int)*(size));
			}
		}
	}
}

int main(void) {
	vector<int> vec = getRandomVector(1000, 10);
	printVector(vec);
	radixSort(vec.data(), 10 ,3);
	printVector(vec);
}