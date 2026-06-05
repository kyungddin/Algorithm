#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> map[10001];
vector<int> tmp;
vector<int> result;

void DFS(int num, int depth, int limit) {
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
		DFS(map[num][i], depth + 1, limit);
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

	sort(tmp.begin(), tmp.end());

	for (i = 0; i < tmp.size(); i++) {
		x = tmp[i];
		for (j = i; j < tmp.size(); j++) {
			map[x].push_back(tmp[j]);
		}
		sort(map[x].begin(), map[x].end());
	}

	result.clear();

	for (i = 0; i < n; i++) {
		x = tmp[i];
		DFS(x, 1, m);
	}
}