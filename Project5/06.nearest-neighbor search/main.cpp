#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

#define DIM 16
#define N 10000

using namespace std;

//0~(1.0)사이의 값을 갖는 d차원의 벡터 생성
vector<double> getRandomVector(int d) {
	vector<double> vec;

	srand((unsigned int)time(0));
	for (int i = 0; i < d; i++) vec.push_back(rand() / (double)RAND_MAX);
	//random_shuffle(vec.begin(), vec.end());
	return vec;
}

int bf_nnSearch(const vector<vector<double>> &data, const vector<double> &query) {
	int n = N; int d = DIM;
	double best_dist = DBL_MAX; int best_idx;
	for (int i = 0; i < data.size(); i++) {
		double dist = 0;
		for (int j = 0; j < d; j++) {
			dist += (data[i][j] - query[j])*(data[i][j] - query[j]);
		}
		cout << dist << endl;
		if (best_dist > dist) {
			best_dist = dist; best_idx = i;
		}
	}
	return best_idx;
}

int main(void) {
	vector<vector<double>> data;
	for (int i = 0; i < N; i++)
		data.push_back(getRandomVector(DIM));

	vector<double> query = getRandomVector(DIM);
	clock_t start = clock();
	cout << bf_nnSearch(data, query) << endl;
	clock_t end = clock();
	double time = double(end - start) / CLOCKS_PER_SEC;
	cout << time << endl;
	return 0;
}