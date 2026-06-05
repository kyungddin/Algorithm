#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

bool arr[50][50] = {};
vector<int> result;
queue<pair<int, int>> q;

int cnt = 0;
int house = 0;

void BFS(int a, int b, int x, int y);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, k, t, i, j, q, w;
	cin >> t;

	int x, y;
	for (i = 0; i < t; i++) {
		cin >> m >> n >> k;
		for (j = 0; j < k; j++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (q = 0; q < m; q++) {
			for (w = 0; w < n; w++) {
				if (arr[q][w] == 1) {
					BFS(q, w, m, n);
					house++;
					result.push_back(cnt);
					cnt = 0;
				}
			}
		}

		for (q = 0; q < m; q++) {
			for (w = 0; w < n; w++) {
				arr[q][w] = 0;
			}
		}
		cout << house << "\n";
		house = 0;
	}
}

void BFS(int a, int b, int x, int y) {
	arr[a][b] = 0;
	cnt++;
	pair<int, int> c;
	c.first = a;
	c.second = b;
	q.push(c);

	while (q.size() != 0) {
		c = q.front();
		q.pop();
		if (c.first + 1 >= 0 && c.second >= 0  && c.first+1<x && c.second <y && arr[c.first + 1][c.second] == 1) {
			q.push(pair<int, int>(c.first+1, c.second));
			arr[c.first + 1][c.second] = 0;
			cnt++;
		}
		if (c.first - 1 >= 0 && c.second >= 0  && c.first - 1 < x && c.second < y && arr[c.first - 1][c.second] == 1) {
			q.push(pair<int, int>(c.first - 1, c.second));
			arr[c.first - 1][c.second] = 0;
			cnt++;
		}
		if (c.first >= 0 && c.second + 1 >= 0  && c.first < x && c.second + 1 < y && arr[c.first][c.second + 1] == 1) {
			q.push(pair<int, int>(c.first, c.second + 1));
			arr[c.first][c.second + 1] = 0;
			cnt++;
		}
		if (c.first >= 0 && c.second - 1 >= 0  && c.first < x && c.second - 1 < y && arr[c.first][c.second - 1] == 1) {
			q.push(pair<int, int>(c.first, c.second - 1));
			arr[c.first][c.second - 1] = 0;
			cnt++;
		}
	}
}