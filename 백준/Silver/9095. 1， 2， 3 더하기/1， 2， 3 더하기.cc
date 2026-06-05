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

	vector<int> mem(11, 0);
	
	mem[1] = 1;
	mem[2] = 2;
	mem[3] = 4;
	for (i = 4; i <= 10; i++) {
		mem[i] = mem[i - 3] + mem[i - 2] + mem[i - 1];
	}

	int tmp;

	for (i = 0; i < n; i++) {
		cin >> tmp;
		cout << mem[tmp] << "\n";
	}
}