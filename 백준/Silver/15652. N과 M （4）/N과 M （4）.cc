#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> map[9];
vector<int> tmp;

void DFS(int num, int depth, int limit) {
	tmp.push_back(num);

	if (depth == limit) {
		for (int i = 0; i < tmp.size(); i++) {
			cout << tmp[i] << " ";
		}
		cout << "\n";
		tmp.pop_back();

		return;
	}

	for (int i = 0; i < map[num].size(); i++) {
		DFS(map[num][i], depth + 1, limit);
	}

	tmp.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int n, m;
	
	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			map[i].push_back(j);
		}
	}

	for (i = 1; i <= n; i++) {
		DFS(i, 1, m);
	}
}