#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000000

using namespace std;

int graph[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, j, k;
	
	int N;
	cin >> N;

	fill(&graph[0][0], &graph[0][0] + 101 * 101, MAX);

	int x;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> x;
			if (x == 0) continue;
			else graph[i][j] = 0;
		}
	}

	for (k = 1; k < 101; k++) {
		for (i = 1; i < 101; i++) {
			for (j = 1; j < 101; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (graph[i][j] == MAX) cout << "0 ";
			else cout << "1 ";
		}
		cout << "\n";
	}
}