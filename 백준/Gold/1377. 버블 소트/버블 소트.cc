#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int i;
	int tmp;
	int max=0;

	cin >> n;
	vector<pair<int, int>> arr(n);
	vector<int> result;

	for (i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < n; i++) {
		tmp = arr[i].second - i;
		result.push_back(tmp);
	}

	max = result[0];
	for (i = 1; i < n; i++) {
		if (max < result[i]) {
			max = result[i];
		}
	}

	cout << max + 1;
}