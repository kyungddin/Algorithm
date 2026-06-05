#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> degree;
vector<bool> visit;
vector<vector<int>> graph;
vector<int> result;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;

	int n, m;
	cin >> n >> m;

	degree.resize(n + 1, 0);
	visit.resize(n + 1, 0);
	graph.resize(n + 1);
	result.resize(n + 1, 0);

	int a, b;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}

	int x;
	int cnt = 1;

	for (i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
			visit[i] = 1;
			result[i] = cnt;
		}
	}

	cnt++;

	while (!q.empty()) {
		x = q.front();
		q.pop();

		for (i = 0; i < graph[x].size(); i++) {
			degree[graph[x][i]]--;
			if (degree[graph[x][i]] == 0 && visit[graph[x][i]] == 0) {
				visit[graph[x][i]] = 1;
				q.push(graph[x][i]);
				result[graph[x][i]] = result[x]+1;
			}
		}
	}

	for (i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}
}