#include <iostream>
#define MOD 1234567891

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	char arr[1000];
	long long sum = 0;
	long long r = 1;

	cin >> n >> arr;

	for (int i = 0; i < n; i++) {
		long long tmp = arr[i] - 'a' + 1;
		sum = (sum + (tmp * r) % MOD) % MOD;
		r = (r * 31) % MOD;
	}

	cout << sum;
}
