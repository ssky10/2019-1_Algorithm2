#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;

#define MAX_DIM 150
#define N 1000000

struct kd_node_t {
	double x[MAX_DIM];
	struct kd_node_t *left, *right;
};

inline double dist(struct kd_node_t *a, struct kd_node_t *b, int dim)
{
	double t, d = 0;
	while (dim--) {
		t = a->x[dim] - b->x[dim];
		d += t * t;
	}
	return d;
}
inline void swap(struct kd_node_t *x, struct kd_node_t *y) {
	double tmp[MAX_DIM];
	memcpy(tmp, x->x, sizeof(tmp));
	memcpy(x->x, y->x, sizeof(tmp));
	memcpy(y->x, tmp, sizeof(tmp));
}


/* see quickselect method */
struct kd_node_t* find_median(struct kd_node_t *start, struct kd_node_t *end, int idx)
{
	if (end <= start) return NULL;
	if (end == start + 1)
		return start;

	struct kd_node_t *p, *store, *md = start + (end - start) / 2;
	double pivot;
	while (1) {
		pivot = md->x[idx];

		swap(md, end - 1);
		for (store = p = start; p < end; p++) {
			if (p->x[idx] < pivot) {
				if (p != store)
					swap(p, store);
				store++;
			}
		}
		swap(store, end - 1);

		/* median has duplicate values */
		if (store->x[idx] == md->x[idx])
			return md;

		if (store > md) end = store;
		else        start = store;
	}
}

struct kd_node_t* make_tree(struct kd_node_t *t, int len, int i, int dim)
{
	struct kd_node_t *n;

	if (!len) return 0;

	if ((n = find_median(t, t + len, i))) {
		i = (i + 1) % dim;
		n->left = make_tree(t, n - t, i, dim);
		n->right = make_tree(n + 1, t + len - (n + 1), i, dim);
	}
	return n;
}

/* global variable, so sue me */
int visited;

void nearest(struct kd_node_t *root, struct kd_node_t *nd, int i, int dim,
	struct kd_node_t **best, double *best_dist)
{
	double d, dx, dx2;

	if (!root) return;
	d = dist(root, nd, dim);
	dx = root->x[i] - nd->x[i];
	dx2 = dx * dx;

	visited++;

	if (!*best || d < *best_dist) {
		*best_dist = d;
		*best = root;
	}

	/* if chance of exact match is high */
	if (!*best_dist) return;

	if (++i >= dim) i = 0;

	nearest(dx > 0 ? root->left : root->right, nd, i, dim, best, best_dist);
	if (dx2 >= *best_dist) return;
	nearest(dx > 0 ? root->right : root->left, nd, i, dim, best, best_dist);
}

double bf_nnSearch(int d, struct kd_node_t wp[], struct kd_node_t query) {
	int n = N;
	double best_dist = DBL_MAX; int best_idx;
	for (int i = 0; i < n; i++) {
		double dist = 0;
		for (int j = 0; j < d; j++) {
			dist += (wp[i].x[j] - query.x[j])*(wp[i].x[j] - query.x[j]);
		}
		if (best_dist > dist) {
			best_dist = dist; best_idx = i;
		}
	}
	return best_dist;
}

#define rand1() (rand() / (double)RAND_MAX)
void rand_pt(struct kd_node_t *v) {
	for (int i = 0; i < MAX_DIM; i++) {
		(*v).x[i] = rand1();
	}
}

double kd_nnSearch(int d, struct kd_node_t wp[], struct kd_node_t query)
{	
	struct kd_node_t *found;
	double best_dist;
	found = 0;
	visited = 0;
	nearest(wp, &query, 0, d, &found, &best_dist);

	return best_dist;
}

int main() {
	struct kd_node_t *root, *million;
	million = (struct kd_node_t*) calloc(N, sizeof(struct kd_node_t));
	srand(time(0));
	for (int i = 0; i < N; i++) rand_pt(&million[i]);

	struct kd_node_t *wp;
	struct kd_node_t testNode;
	rand_pt(&testNode);

	int d = 4, exit = 0;
	do {
		double totalTime = 0, dist;
		double bfTime = 0, kdTime = 0;

		cout << "Brute-force의 d = " << d << " 평균속도:";
		for (int i = 0; i < 100; i++) {
			clock_t start = clock();
			dist = bf_nnSearch(d, million, testNode);
			clock_t end = clock();
			totalTime += (end - start) / double(CLOCKS_PER_SEC);
		}
		bfTime = totalTime / 100.0;
		cout << bfTime << endl;
		cout << "Brute-force의 최소 거리:" << dist << endl;

		totalTime = 0;

		wp = make_tree(million, N, 0, d);
		
		cout << "k-d tree의 d = " << d << " 평균속도:";
		for (int i = 0; i < 100; i++) {
			clock_t start = clock();
			dist = kd_nnSearch(d, wp, testNode);
			clock_t end = clock();
			totalTime += (end - start) / double(CLOCKS_PER_SEC);
		}
		kdTime = totalTime / 100.0;
		cout << kdTime << endl;
		cout << "k-d tree의 최소 거리:" << dist << endl;
		d++;

		cout << "--------------------------------------------------" << endl;

		if (kdTime > bfTime) exit = 1;

	} while (exit!=1);

}