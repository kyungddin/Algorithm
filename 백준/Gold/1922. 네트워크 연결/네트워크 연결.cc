#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF 9999999 
#define MAX_V 1001   

using namespace std;

int v, e, src;
int w[MAX_V][MAX_V];    
int vertex[MAX_V][3];  

void swap(int* a1, int* a2);
void min_heapify(int* arr, int i, int* length);
void build_min_heap(int* arr, int* length);
int extract_min(int* arr, int* length);
void decrease_key(int* heap, int i, int key);
int is_in_heap(int* heap, int length, int u);
int get_heap_index(int* heap, int heap_size, int vertex);
void mst_prim(int vert[][3], int weight[][MAX_V], int root);


void swap(int* a1, int* a2) {
	int tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

void min_heapify(int* arr, int i, int* length)
{
	int smallest;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int u = arr[i];

	if (left < *length && vertex[arr[left]][1] < vertex[u][1]) {
		smallest = left;
	}
	else {
		smallest = i;
	}

	if (right < *length && vertex[arr[right]][1] < vertex[arr[smallest]][1]) {
		smallest = right;
	}

	if (smallest != i) {
		swap(arr + i, arr + smallest);
		min_heapify(arr, smallest, length);
	}
}

void build_min_heap(int* arr, int* length)
{
	for (int i = (*length) / 2 - 1; i >= 0; i--) {
		min_heapify(arr, i, length);
	}
}

int extract_min(int* arr, int* length)
{
	int min = arr[0];
	arr[0] = arr[(*length) - 1];
	(*length)--;
	min_heapify(arr, 0, length);
	return min;
}

void decrease_key(int* heap, int i, int key) {
	while (i > 0 && vertex[heap[(i - 1) / 2]][1] > vertex[heap[i]][1]) {
		swap(&heap[i], &heap[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

int is_in_heap(int* heap, int length, int u) {
	for (int i = 0; i < length; i++) {
		if (heap[i] == u) return 1;
	}
	return 0;
}

int get_heap_index(int* heap, int heap_size, int vertex) {
	for (int i = 0; i < heap_size; i++) {
		if (heap[i] == vertex) return i;
	}
	return -1;
}

void mst_prim(int vert[][3], int weight[][MAX_V], int root)
{
	int u;
	int heap[MAX_V];    
	int heap_size = v;

	for (int i = 0; i < v; i++) { 
		heap[i] = i;
		vert[i][0] = i;
		vert[i][1] = INF;
		vert[i][2] = -1;
	}

	vert[root][1] = 0;

	build_min_heap(heap, &heap_size);

	while (heap_size > 0) {
		u = extract_min(heap, &heap_size);

		for (int i = 0; i < v; i++) {
			if (weight[u][i] != INF && is_in_heap(heap, heap_size, i)) {
				if (weight[u][i] < vert[i][1]) {
					vert[i][2] = u;
					vert[i][1] = weight[u][i];

					int idx = get_heap_index(heap, heap_size, i);
					if (idx != -1) {
						decrease_key(heap, idx, vert[i][1]);
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;

	cin >> v >> e;

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			w[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		if (w[a - 1][b - 1] > c) {
			w[a - 1][b - 1] = c;
			w[b - 1][a - 1] = c;
		}
	}
	src = 0;
	mst_prim(vertex, w, src);

	long long total_cost = 0; 
	for (int i = 0; i < v; i++) {
		if (vertex[i][1] != INF) {
			total_cost += vertex[i][1];
		}
	}

	cout << total_cost << endl;

	return 0;
}