#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 10001
#define MAX_E 100001
#define INF 2000000000

typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    Edge* head;
} AdjList;

typedef struct {
    int vertex;
    int key;
} HeapNode;

int v, e;
AdjList adj[MAX_V];
int vertex[MAX_V][3]; 

HeapNode heap[MAX_V];
int heap_size = 0;
int in_heap[MAX_V];

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify_up(int i) {
    while (i > 0 && vertex[heap[i].vertex][1] < vertex[heap[(i - 1) / 2].vertex][1]) {
        swap(&heap[i].vertex, &heap[(i - 1) / 2].vertex);
        i = (i - 1) / 2;
    }
}

void heapify_down(int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < heap_size && vertex[heap[l].vertex][1] < vertex[heap[smallest].vertex][1])
        smallest = l;
    if (r < heap_size && vertex[heap[r].vertex][1] < vertex[heap[smallest].vertex][1])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i].vertex, &heap[smallest].vertex);
        heapify_down(smallest);
    }
}

void build_heap() {
    for (int i = heap_size / 2 - 1; i >= 0; i--)
        heapify_down(i);
}

int extract_min() {
    int min = heap[0].vertex;
    heap[0] = heap[--heap_size];
    heapify_down(0);
    return min;
}

int get_index_in_heap(int u) {
    for (int i = 0; i < heap_size; i++) {
        if (heap[i].vertex == u) return i;
    }
    return -1;
}

void decrease_key(int u, int new_key) {
    int i = get_index_in_heap(u);
    if (i == -1) return;
    vertex[u][1] = new_key;
    heapify_up(i);
}

void add_edge(int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = adj[u].head;
    adj[u].head = e;
}

void mst_prim(int start) {
    for (int i = 1; i <= v; i++) {
        vertex[i][0] = i;
        vertex[i][1] = INF;
        vertex[i][2] = -1;
        heap[i - 1].vertex = i;
        in_heap[i] = 1;
    }
    heap_size = v;
    vertex[start][1] = 0;
    build_heap();

    long long total = 0;

    while (heap_size > 0) {
        int u = extract_min();
        in_heap[u] = 0;
        total += vertex[u][1];

        for (Edge* e = adj[u].head; e != NULL; e = e->next) {
            int v_ = e->to;
            int w = e->weight;

            if (in_heap[v_] && w < vertex[v_][1]) {
                vertex[v_][2] = u;
                decrease_key(v_, w);
            }
        }
    }

    printf("%lld\n", total);
}

int main() {
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }

    mst_prim(1);
}