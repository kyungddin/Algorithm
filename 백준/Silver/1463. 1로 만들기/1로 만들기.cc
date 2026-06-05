#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> mem(1000001,0);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, n;
	cin >> n;

	for (i = 2; i <= n; i++) {
		mem[i] = mem[i - 1] + 1;
		if (i % 2 == 0) mem[i] = min(mem[i / 2] + 1, mem[i]);
		if (i % 3 == 0) mem[i] = min(mem[i / 3] + 1, mem[i]);
	}

	cout << mem[n];
}