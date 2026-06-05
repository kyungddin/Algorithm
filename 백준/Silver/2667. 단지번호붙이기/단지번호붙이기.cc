#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

bool arr[25][25] = {};
vector<int> result;
queue<pair<int, int>> q;

int cnt = 0;
int house = 0;

void BFS(int a, int b, int l);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i, j;
	cin >> n;

	string m;
	for (i = 0; i < n; i++) {
		cin >> m;
		for (j = 0; j < n; j++) {
			arr[i][j] = m[j]-'0';
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				BFS(i, j, n);
				house++;
				result.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(result.begin(), result.end());


	cout << house << "\n";
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}

void BFS(int a, int b, int l) {
	arr[a][b] = 0;
	cnt++;
	pair<int, int> c;
	c.first = a;
	c.second = b;
	q.push(c);

	while (q.size() != 0) {
		c = q.front();
		q.pop();
		if (c.first + 1 >= 0 && c.second >= 0  && c.first+1<l && c.second <l && arr[c.first + 1][c.second] == 1) {
			q.push(pair<int, int>(c.first+1, c.second));
			arr[c.first + 1][c.second] = 0;
			cnt++;
		}
		if (c.first - 1 >= 0 && c.second >= 0  && c.first - 1 < l && c.second < l && arr[c.first - 1][c.second] == 1) {
			q.push(pair<int, int>(c.first - 1, c.second));
			arr[c.first - 1][c.second] = 0;
			cnt++;
		}
		if (c.first >= 0 && c.second + 1 >= 0  && c.first < l && c.second + 1 < l && arr[c.first][c.second + 1] == 1) {
			q.push(pair<int, int>(c.first, c.second + 1));
			arr[c.first][c.second + 1] = 0;
			cnt++;
		}
		if (c.first >= 0 && c.second - 1 >= 0  && c.first < l && c.second - 1 < l && arr[c.first][c.second - 1] == 1) {
			q.push(pair<int, int>(c.first, c.second - 1));
			arr[c.first][c.second - 1] = 0;
			cnt++;
		}
	}
}