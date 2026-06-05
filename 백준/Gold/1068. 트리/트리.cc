#include <iostream>
#include <vector>

using namespace std;

void DFS(int num, int del);

vector<int> map[100001];
vector<bool> visit(100001, 0);
vector<int> result(100001);

int answer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	int root = 0;

	int n, k;
	cin >> n;

	int a, b;
	for (i = 0; i < n; i++) {
		cin >> a;
		if (a == -1) root = i;
		else {
			map[i].push_back(a);
			map[a].push_back(i);
		}
	}

	cin >> k;

	if (k == root) {
		cout << 0 << "\n";
		return 0;
	}

	DFS(root, k);

	cout << answer;
}

void DFS(int num, int del) {
	visit[num] = true;

	int cnt = 0;

	for (int i = 0; i < map[num].size(); i++) {

		if (visit[map[num][i]] == false && map[num][i]!=del) {
			result[map[num][i]] = num;
			DFS(map[num][i], del);
			cnt++;
		}
	}

	if (cnt == 0) answer++;
}