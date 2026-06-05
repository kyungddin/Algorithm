#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visit(100001, -1);
vector<int> map[100001];

int cnt = 0;

void DFS(int num, int depth);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r, i, j;

	cin >> n >> m >> r;

	int a, b;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (i = 1; i <= n; i++) {
		sort(map[i].begin(), map[i].end());
	}

	DFS(r, 0);

	for (i = 1; i <= n; i++) {
		cout << visit[i] << "\n";
	}
}

void DFS(int num, int depth) {
	visit[num] = depth;

	int i;
	for (i = 0; i < map[num].size(); i++) {
		if (visit[map[num][i]] == -1) {
			DFS(map[num][i], depth+1);
		}
	}
}