#include <iostream>
#include <vector>

using namespace std;

vector<int> map[20001];
vector<bool> visit(20001,0);
vector<int> s(20001, 0);

bool check = 1;

void DFS(int num, int color);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k;
	int v, e;
	int a, b;

	cin >> k;

	for (i = 0; i < k; i++) {
		cin >> v >> e;
		for (j = 0; j < e; j++) {
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}

		for (j = 1; j <= v; j++) {
			if (check == true) {
				if (visit[j] == false) {
					DFS(j, 1);
				}
			}
			else {
				break;
			}
		}

		if (check == true) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

		check = true;
		for (j = 1; j <= v; j++) {
			map[j].clear();
			visit[j] = 0;
			s[j] = 0;
		}
	}
}

void DFS(int num, int color) {

	visit[num] = 1;
	s[num] = color;

	int i;
	for (i = 0; i < map[num].size(); i++) {
		if (visit[map[num][i]] == 0) {
			DFS(map[num][i], 3-color);
		}
		else if (s[num] == s[map[num][i]]) {
			check = false;
		}
	}
}