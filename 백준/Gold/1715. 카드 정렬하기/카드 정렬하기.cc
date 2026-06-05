#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> arr;

	int i;
	int n;
	int tmp;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> tmp;
		arr.push(tmp);
	}

	int sum = 0;
	
	int data1, data2;

	while (arr.size()!=1) {
		data1 = arr.top();
		arr.pop();
		data2 = arr.top();
		arr.pop();
		tmp = data1 + data2;
		arr.push(tmp);
		sum += tmp;
	}

	cout << sum;
}