#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

void DFS(int num);
void BFS(int num);

vector<int> map[1001];
vector<bool> visit1(1001, 0);
vector<bool> visit2(1001, 0);
deque<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	int n, m, v;
	cin >> n >> m >> v;
	
	int a, b;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	} // 인접 리스트 완성

	for (i = 1; i <= n; i++) {
		sort(map[i].begin(), map[i].end());
	}

	DFS(v);
	cout << "\n";
	BFS(v);
}

void DFS(int num) {
	visit1[num] = true;
	cout << num << " ";
	for (int j = 0; j < map[num].size(); j++) {
		if (visit1[map[num][j]] == false) {
			DFS(map[num][j]);
		}
	}
}

void BFS(int num) {
	int p;
	visit2[num] = true;
	cout << num << " ";
	for (int k = 0; k < map[num].size(); k++) {
		q.push_back(map[num][k]);
	}
	while (q.size() != 0) {
		p = q[0];
		q.pop_front();
		if (visit2[p] == false) {
			visit2[p] = true;
			cout << p << " ";
			for (int k = 0; k < map[p].size(); k++) {
				q.push_back(map[p][k]);
			}
		}
	}
}