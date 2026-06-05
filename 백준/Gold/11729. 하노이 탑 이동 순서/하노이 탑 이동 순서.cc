#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> result;
int cnt = 0;

void hanoi_tower(int n, int from, int tmp, int to) {
	if (n == 1) {
		result.push_back(pair<int, int>(from, to));
		cnt++;
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		result.push_back(pair<int, int>(from, to));
		cnt++;
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	int N;
	cin >> N;

	hanoi_tower(N, 1, 2, 3);

	cout << cnt << "\n";
	for (i = 0; i < result.size(); i++) {
		cout << result[i].first << " " << result[i].second << "\n";
	}
}