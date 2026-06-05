#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool pal_checker(int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int n;
	vector<int> arr;

	for (i = 0; i <= 1003001; i++) {
		arr.push_back(i);
	}

	arr[1] = 0;

	for (i = 2; i <= 1003001; i++) {
		if (arr[i] == 0) continue;
		else {
			for (j = i + i; j <= 1003001; j += i) {
				arr[j] = 0;
			}
		}
	}

	cin >> n;

	for (i = n; i <= 1003001; i++) {
		if (arr[i] == 0) continue;
		else {
			if (pal_checker(arr[i])) {
				cout << arr[i];
				return 0;
			}
		}
	}
}

bool pal_checker(int num) {
	string tmp = to_string(num);
	int len = tmp.size();

	for (int i = 0; i < len / 2; i++) {
		if (tmp[i] != tmp[len - 1 - i]) return false;
	}
	return true;
}
