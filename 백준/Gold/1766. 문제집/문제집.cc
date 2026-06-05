#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> map[32001];
vector<int> degree(32001, 0);
priority_queue<int, vector<int>, greater<int>> q;

/*
template<
	class T,                       // 저장할 데이터 타입
	class Container = vector<T>,   // 내부에서 사용할 컨테이너 (기본값: vector)
	class Compare = less<T>        // 정렬 기준 (기본값: less -> 최대 힙)
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int i;
	int a, b;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		map[a].push_back(b);
		degree[b]++;
	}

	for (i = 1; i <= n; i++) {
		if (degree[i] == 0) q.push(i);
	}

	int tmp;
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		cout << tmp << " ";

		for (i = 0; i < map[tmp].size(); i++) {
			degree[map[tmp][i]]--;
			if (degree[map[tmp][i]] == 0) {
				q.push(map[tmp][i]);
			}
		}
	}
}