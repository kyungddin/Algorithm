#include <iostream>
#include <vector>

using namespace std;

int comb(int a, int b, vector<vector<int>> &dp) {
	if (a == b || b == 0) return 1;
	if (dp[a][b] != -1) return dp[a][b];
	return dp[a][b] = comb(a - 1, b - 1, dp) + comb(a - 1, b, dp);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int i;
	int a, b;

	for (i = 0; i < n; i++) {
		cin >> a >> b;

		vector<vector<int>> arr(b + 1, vector<int>(a + 1, -1));

		cout << comb(b, a, arr) << "\n";
	}
}