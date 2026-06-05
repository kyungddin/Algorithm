#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> map[10001];
vector<bool> visit(10001, 0);
vector<int> tmp;
vector<int> result;

void DFS(int num, int depth, int limit) {
	visit[num] = true;
	result.push_back(num);

	if (depth == limit) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		result.pop_back();

		return;
	}

	for (int i = 0; i < map[num].size(); i++) {
		if (visit[map[num][i]] == 0) {
			visit[map[num][i]] = 1;
			DFS(map[num][i], depth + 1, limit);
			visit[map[num][i]] = 0;
		}
	}

	result.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int n, m;
	int x, y;

	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		cin >> x;
		tmp.push_back(x);
	}

	for (i = 0; i < tmp.size(); i++) {
		x = tmp[i];
		for (j = 0; j < tmp.size(); j++) {
			if(tmp[j]!=x) map[x].push_back(tmp[j]);
		}
		sort(map[x].begin(), map[x].end());
	}

	sort(tmp.begin(), tmp.end());

	result.clear();

	for (i = 0; i < n; i++) {
		fill(visit.begin(), visit.end(), 0);
		x = tmp[i];
		DFS(x, 1, m);
	}
}