#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1000000000

using namespace std;

int graph[101][101];
vector<pair<int, int>> result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, j, k;
	
	int N, M;
	cin >> N >> M;

	fill(&graph[0][0], &graph[0][0] + 101 * 101, MAX);

	int a, b;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (i = 1; i <= N; i++) {
		graph[i][i] = 0;
	}

	for (k = 1; k < 101; k++) {
		for (i = 1; i < 101; i++) {
			for (j = 1; j < 101; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int sum;
	
	for (i = 1; i <= N; i++) {
		sum = 0;
		for (j = 1; j <= N; j++) {
			sum += graph[i][j];
		}
		result.push_back(make_pair(sum, i));
	} 

	sort(result.begin(), result.end());

	cout << result.front().second;
}