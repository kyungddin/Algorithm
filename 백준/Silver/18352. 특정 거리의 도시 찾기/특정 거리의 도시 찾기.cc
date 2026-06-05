#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> map[300001];
vector<int> visit(300001, -1);
vector<int> result;
queue<int> q;

int dist = 1;

void BFS(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, x;
	cin >> n >> m >> k >> x;

	int i;
	int a, b;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
	}

	BFS(x);

	for (i = 1; i <= n; i++) {
		if (visit[i] == k) {
			result.push_back(i);
		}
	}

	sort(result.begin(), result.end());

	if (result.size() == 0) {
		cout << "-1";
		return 0;
	}

	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}

void BFS(int num) {
	visit[num] = 0;
	q.push(num);

	int i;
	int tmp;

	while (q.size() != 0) {
		tmp = q.front();
		q.pop();
		if (map[tmp].size()!=0) {
			for (i = 0; i < map[tmp].size(); i++) {
				if (visit[map[tmp][i]] == -1) {
					q.push(map[tmp][i]);
					visit[map[tmp][i]] = visit[tmp] + 1;
				}
			}
		}
	}
}