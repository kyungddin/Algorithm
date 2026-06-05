#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> visit(100001, 0);
vector<int> map[100001];
queue<int> q;

int cnt = 0;

void BFS(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r, i;

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

	BFS(r);

	for (i = 1; i <= n; i++) {
		cout << visit[i] << "\n";
	}
}

void BFS(int num) {
	int tmp, i;

	cnt++;
	visit[num] = cnt;
	q.push(num);

	while (q.size() != 0) {
		tmp = q.front();
		q.pop();

		for (i = 0; i < map[tmp].size(); i++) {
			if (visit[map[tmp][i]] == 0) {
				cnt++;
				visit[map[tmp][i]] = cnt;
				q.push(map[tmp][i]);
			}
		}
	}
}