#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> truth;
vector<int> party[50];

void unionfunc(int a, int b);
int find(int a);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k;
	int n, m;

	cin >> n >> m;

	parent.resize(n + 1);
	for (i = 1; i <= n; i++) {
		parent[i] = i;
	} // 그래프 초기화

	int x;
	int tmp;

	cin >> x;
	for (i = 0; i < x; i++) {
		cin >> tmp;
		truth.push_back(tmp);
	} // 진실을 아는 사람을 truth에 저장

	int cnt = 0;

	for (i = 0; i < m; i++) {
		cin >> x;
		for (j = 0; j < x; j++) {
			cin >> tmp;
			party[i].push_back(tmp);
		} // 파티에 오는 인원 저장

		sort(party[i].begin(), party[i].end());

		if (x == 1) continue;

		for (j = 0; j < x - 1; j++) {
			unionfunc(party[i][j], party[i][j + 1]);
		} // 파티 정보를 이용해 유니온 수행
	}

	for (i = 0; i < m; i++) {

		int first = party[i][0];
		bool checker = false;

		for (j = 0; j < truth.size(); j++) {
			if (find(first) == find(truth[j])) {
				checker = true;
			}
		}

		if (checker == false) cnt++;
	}

	cout << cnt;
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		parent[b] = a;
	}
}

int find(int a) {
	if (a == parent[a]) {
		return a;
	}
	return parent[a] = find(parent[a]);
}