#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int i;
	int tmp;
	int sum = 0;
	for (i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
		sum += tmp;
	} // 강의 길이 저장해주기

	int start = *max_element(arr.begin(), arr.end());
	int end = sum;
	// 시작과 종료 index 초기화

	int mid;
	int count = 0;
	sum = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		count = 0;
		sum = 0;
		for (i = 0; i < n; i++) {
			sum += arr[i];
			if (sum > mid) {
				count++;
				sum = arr[i];
			}
		}

		count++;

		if (count <= m) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	cout << start;
}