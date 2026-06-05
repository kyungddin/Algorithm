#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, n;
	cin >> n;

	vector<int> mem(n + 1, 0);
	vector<int> dp(n + 1, 0);

	int tmp;

	for (i = 1; i <= n; i++) {
		cin >> tmp;
		mem[i] = tmp;
	}

	dp[1] = mem[1];
	dp[2] = mem[2] + mem[1];

	for (i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + mem[i], dp[i - 3] + mem[i - 1] + mem[i]);
	}

	cout << dp[n];
}