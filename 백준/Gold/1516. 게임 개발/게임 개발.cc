#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> map[501];
vector<int> degree;
vector<int> w_time;
vector<int> result;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	int N;
	cin >> N;

	degree.resize(N + 1, 0);
	w_time.resize(N + 1, 0);
	result.resize(N + 1, 0);

	int t;
	int x=0;
	for (i = 1; i <= N; i++) {
		cin >> t;
		w_time[i] = t;
		// 각 건물별 작업 시간 저장

		while (true) {
			cin >> x;
			if (x == -1) break;
			map[x].push_back(i);
			degree[i]++;
		}
		// 인접 리스트 및 degree 세팅
	}

	for (i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}

	int tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();

		for (int j = 0; j < map[tmp].size(); j++) {
			degree[map[tmp][j]]--;
			result[map[tmp][j]] = max(result[map[tmp][j]], result[tmp] + w_time[tmp]);
			if (degree[map[tmp][j]] == 0) {
				q.push(map[tmp][j]);
			}
		}
	}

	for (i = 1; i <= N; i++) {
		result[i] += w_time[i];
		cout << result[i] << "\n";
	}
}