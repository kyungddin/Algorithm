#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000000

using namespace std;

int graph[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k;

	int N, M;
	cin >> N >> M;

	fill(&graph[0][0], &graph[0][0] + 101 * 101, MAX);
	for (i = 0; i < 101; i++) {
		graph[i][i] = 0;
	}

	int a, b, c;
	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (graph[i][j] == MAX) cout << "0 ";
			else cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}