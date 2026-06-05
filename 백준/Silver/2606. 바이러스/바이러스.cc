#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> map[101];
vector<bool> visit(101, 0);
int cnt = 0;

void DFS(int num) {
	visit[num] = true;
	int i;
	for (i = map[num].size() - 1; i >= 0; i--) {
		if (visit[map[num][i]] == false) {
			visit[map[num][i]] = true;
			cnt++;
			DFS(map[num][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	int u, v;
	cin >> u >> v;

	int a, b;
	for (i = 0; i < v; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	DFS(1);

	cout << cnt;
}