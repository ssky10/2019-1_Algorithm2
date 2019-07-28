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
	//random_shuffle(vec.begin(), vec.end());
	return vec;
}

vector<int> getSortedVector(int n) {
	vector<int> vec;
	srand((unsigned int)time(0));
	for (int i = 0; i < n; i++) vec.push_back(rand() % 100);
	sort(vec.begin(), vec.end());
	return vec;
}

void printVector(const vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int binarySearch(const vector<int> &vec, int keyword) {
	int from = 0, to = vec.size() - 1, mid;
	while (to-from > 0)
	{
		mid = (from + to) / 2;
		if (vec[mid] == keyword) return mid;
		else if (vec[mid] < keyword) from = mid + 1;
		else if (vec[mid] > keyword) to = mid - 1;
	}
	return -1;
}

int main(void) {
	vector<int> vec = getSortedVector(50);
	printVector(vec);
	cout << binarySearch(vec, 5) << endl;
}