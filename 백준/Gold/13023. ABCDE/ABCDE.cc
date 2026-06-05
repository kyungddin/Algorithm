#include <iostream>
#include <vector>

using namespace std;

int cnt=0;
vector<int> map[2001];
vector<bool> visit(2001, 0);

void DFS(int num, int depth) {
	if (depth == 5) {
		cout << "1";
		exit(0);
	}

	visit[num] = true;

	for (int j = map[num].size() - 1; j >= 0; j--) {
		if (visit[map[num][j]] == false) {
			cnt++;
			DFS(map[num][j], depth+1);
		}
	}

	visit[num] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v;
	int i;
	cin >> u >> v;

	int a, b;

	for (i = 0; i < v; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	} // 인접 리스트 생성

	for (i = 0; i < u; i++) {
		if (visit[i] == false) DFS(i, 1);
	}

	cout << "0";
}