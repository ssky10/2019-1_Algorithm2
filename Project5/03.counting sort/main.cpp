#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

//0~(n-1)������ ���ڸ� �ϳ��� ���ҷ� ������
//���ĵ��� ���� vector ��ü�� ��ȯ
vector<int> getRandomVector(int n) {
	vector<int> vec;
	for (int i = 0; i < n; i++) vec.push_back(i);
	srand((unsigned int)time(0));
	random_shuffle(vec.begin(), vec.end());
	return vec;
}

//0~(k-1)������ ������ n�� ������ ���ͻ���
vector<int> getRandomVector(int k, int n) {
	vector<int> vec;
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++) vec.push_back(rand()%k);
	return vec;
}

void printVector(const vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

vector<int> countingSort(const vector<int>& vec, int k) {
	vector<int> sorted;
	int* count = new int[k] {0};
	for (int i = 0; i < vec.size(); i++) {
		count[vec[i]]++;
	}
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < count[i]; j++) {
			sorted.push_back(i);
		}
	}
	return sorted;
}

int main(void) {
	vector<int> vec = getRandomVector(10,10);
	printVector(vec);
	vector<int> result;
	result = countingSort(vec, 10);
	printVector(result);
}