#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> map[9];
vector<bool> visit(9, 0);
vector<int> tmp;

void DFS(int num, int depth, int limit) {
	visit[num] = true;
	tmp.push_back(num);

	if (depth == limit) {
		for (int j = 0; j < tmp.size(); j++) {
			cout << tmp[j] << " ";
		}
		cout << "\n";

		visit[num] = false;
		tmp.pop_back();
		return;
	}

	for (int i = 0; i < map[num].size(); i++) {
		int next = map[num][i];
		if (!visit[next]) {
			DFS(next, depth + 1, limit);
		}
	}

	visit[num] = false;
	tmp.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) map[i].push_back(j);
		}
	}

	for (int i = 1; i <= n; i++) {
		fill(visit.begin(), visit.end(), 0);
		DFS(i, 1, m); 
	}
}
