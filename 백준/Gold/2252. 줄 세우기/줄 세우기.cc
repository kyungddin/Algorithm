#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[32001];
vector<int> degree(32001, 0);
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	degree.resize(n + 1);

	int i;
	int a, b;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		degree[b]++;
	}

	for (i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	int tmp;
	while (q.size() != 0) {
		tmp = q.front();
		q.pop();
		cout << tmp << " ";
		
		for (i = 0; i < map[tmp].size(); i++) {
			degree[map[tmp][i]]--;
			if (degree[map[tmp][i]] == 0) {
				q.push(map[tmp][i]);
			}
		}
		
	}
}