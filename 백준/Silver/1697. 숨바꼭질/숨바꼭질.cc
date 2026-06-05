#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[100001];
vector<bool> visit(100001, 0);
queue<pair<int, int>> q;

int BFS(int num, int target);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i;
	int n, k;
	cin >> n >> k;

	for (i = 0; i < 100001; i++) {
		if (i - 1 >= 0) {
			map[i].push_back(i - 1);
		}
		if (i + 1 <= 100000) {
			map[i].push_back(i + 1);
		}
		if (i * 2 <= 100000) {
			map[i].push_back(2 * i);
		}
	}

	int result = BFS(n, k);

	cout << result;
}

int BFS(int num, int target) {
	visit[num] = 1;
	q.push(pair<int, int>(num, 0));
	
	int node;
	int time;
	int i;

	while (q.size() != 0) {
		node = q.front().first;
		time = q.front().second;
		q.pop();

		if (node == target) {
			return time;
		}

		for (i = 0; i < map[node].size(); i++) {
			if (visit[map[node][i]] == 0) {
				visit[map[node][i]] = 1;
				q.push(pair<int, int>(map[node][i], time+1));
			}
		}
	}

	return -1;
}