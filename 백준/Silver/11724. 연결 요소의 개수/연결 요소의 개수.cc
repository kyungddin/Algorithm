#include <iostream>
#include <vector>

using namespace std;

vector<int> map[1001];
vector<bool> visit(1001, 0);
int cnt = 0;

void dfs(int num) {
	visit[num] = true;
	int i = map[num].size()-1;
	while (i>=0) {
		if (visit[map[num][i]] != true) {
			dfs(map[num][i]);
			i--;
		}
		else {
			i--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int i;
	int u, v;
	for (i = 0; i < m; i++) {
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	} // 인접리스트 생성

	for (i = 1; i <= n; i++) {
		if (visit[i] == true) continue;
		else {
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt;
}