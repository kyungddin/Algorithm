#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;
	int k, n;
	
	vector<int> arr;

	long long int tmp;
	long long int sum = 0;

	cin >> k >> n;

	for (i = 0; i < k; i++) {
		cin >> tmp;
		sum += tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());
	long long int max = arr.back();
	long long int min = 1;
	long long int mid;
	int count = 0;
	long long int result;

	while (min <= max) {
		mid = (max + min) / 2;
		for (i = 0; i < k; i++) {
			count += (arr[i] / mid);
		}
		if (count < n) {
			max = mid - 1;
			count = 0;
		}
		else {
			min = mid + 1;
			result = mid;
			count = 0;
		}
	}

	cout << result;
}