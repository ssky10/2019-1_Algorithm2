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

vector<int> sort(const vector<int> &vec) {
	vector<int> sorted;
	int tmp;
	for (int i = 0; i < vec.size(); i++) {
		sorted.push_back(vec[i]);
		for (int j = i; (j > 0) && (sorted[j - 1] > sorted[j]); j--) {
			tmp = sorted[j - 1];
			sorted[j - 1] = sorted[j];
			sorted[j] = tmp;
		}
	}
	return sorted;
}

int main(void) {
	vector<int> vec = getRandomVector(100), sorted;
	printVector(vec);
	sorted = sort(vec);
	printVector(sorted);
}