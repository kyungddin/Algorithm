#include <iostream>
#include <vector>

using namespace std;

void DFS(int num);

vector<int> map[100001];
vector<bool> visit(100001, 0);
vector<int> result(100001);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;

	int n;
	cin >> n;

	int a, b;
	for (i = 0; i < n - 1; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	DFS(1);

	for (i = 2; i <= n; i++) {
		cout << result[i] << "\n";
	}
}

void DFS(int num) {
	visit[num] = true;

	for (int i = 0; i < map[num].size(); i++) {
		if (visit[map[num][i]] == false) {
			result[map[num][i]] = num;
			DFS(map[num][i]);
		}
	}
}