#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
bool visit[101][101] = {};
int maze[101][101];

void BFS(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int i, j;
	char word[101];

	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		cin >> word;
		for (j = 1; j <= m; j++) {
			maze[i][j] = word[j-1] - '0';
		}
	} // 미로 완성!!!	

	BFS(n, m);
}

void BFS(int a, int b) {
	pair<int, int> c;

	visit[1][1] = true;
	c.first = 1;
	c.second = 1;
	q.push(c);

	pair<int, int> up;
	pair<int, int> down;
	pair<int, int> right;
	pair<int, int> left;

	while (q.empty() == false) {
		c = q.front();
		q.pop();

		if (c.first == a && c.second == b) {
			cout << maze[c.first][c.second];
			return;
		}

		up.first = c.first-1;
		up.second = c.second;
		if (up.first >= 1 && up.second >= 1 && up.first <= a && up.second <= b &&
			maze[up.first][up.second] != 0 && !visit[up.first][up.second]) {
			q.push(up);
			visit[up.first][up.second] = true;
			maze[up.first][up.second] = maze[c.first][c.second]+1;
		} // 위에 대한 탐색

		down.first = c.first + 1;
		down.second = c.second;
		if (down.first >= 1 && down.second >= 1 && down.first <= a && down.second <= b &&
			maze[down.first][down.second] != 0 && !visit[down.first][down.second]) {
			q.push(down);
			visit[down.first][down.second] = true;
			maze[down.first][down.second] = maze[c.first][c.second] + 1;
		} // 아래에 대한 탐색

		right.first = c.first;
		right.second = c.second+1;
		if (right.first >= 1 && right.second >= 1 && right.first <= a && right.second <= b &&
			maze[right.first][right.second] != 0 && !visit[right.first][right.second]) {
			q.push(right);
			visit[right.first][right.second] = true;
			maze[right.first][right.second] = maze[c.first][c.second] + 1;
		} // 오른쪽

		left.first = c.first;
		left.second = c.second - 1;
		if (left.first >= 1 && left.second >= 1 && left.first <= a && left.second <= b &&
			maze[left.first][left.second] != 0 && !visit[left.first][left.second]) {
			q.push(left);
			visit[left.first][left.second] = true;
			maze[left.first][left.second] = maze[c.first][c.second] + 1;
		} // 왼쪽
	}
}