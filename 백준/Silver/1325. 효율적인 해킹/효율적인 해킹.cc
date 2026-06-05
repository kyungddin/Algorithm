#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> map[10001];
vector<int> r(10001, 0);

void BFS(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int i;
	int a, b;

	cin >> n >> m;

	for (i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
	} // 인접 리스트 채우기

	for (i = 1; i <= n; i++) {
		BFS(i);
	}

	int max = r[1];

	for (i = 2; i <= n; i++) {
		if (max < r[i]) {
			max = r[i];
		}
	}

	for (i = 1; i <= n; i++) {
		if (r[i] == max) {
			cout << i << " ";
		}
	}
}

void BFS(int num) {
	queue<int> q;
	vector<bool> visit(10001, 0);

	visit[num] = true;
	q.push(num);

	int tmp;

	while (q.size() != 0) {
		tmp = q.front();
		q.pop();

		for (int i = 0; i < map[tmp].size(); i++) {
			if (visit[map[tmp][i]] == false) {
				visit[map[tmp][i]] = true;
				q.push(map[tmp][i]);
				r[map[tmp][i]]++;
			}
		}
	}
}