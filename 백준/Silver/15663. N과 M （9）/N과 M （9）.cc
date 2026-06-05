#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
bool visited[8];
int result[8];

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++)
			cout << result[i] << ' ';
		cout << '\n';
		return;
	}
	int prev = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && nums[i] != prev) {
			visited[i] = true;
			result[depth] = nums[i];
			prev = nums[i];
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	nums.resize(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	dfs(0);
}
