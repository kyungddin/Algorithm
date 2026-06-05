#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	int n, k;
	cin >> n >> k;

	long long int start, end;
	long long mid;
	int count = 0;

	start = 1;
	end = k;

	int tmp;
	int result = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		for (i = 1; i <= n; i++) {
			tmp = mid / i;
			if (tmp > n) tmp = n;
			count += tmp;
		}

		if (count >= k) {
			end = mid - 1;
			result = mid;
			count = 0;
		}

		else {
			start = mid + 1;
			count = 0;
		}
	}

	cout << result << "\n";
}