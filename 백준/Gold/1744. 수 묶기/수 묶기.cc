#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> pos;
	priority_queue<int, vector<int>, greater<int>> neg;
	int ones=0;
	int zeros = 0;

	int i;
	int n;
	int tmp;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> tmp;

		if (tmp > 1) {
			pos.push(tmp);
		}
		else if (tmp == 1) {
			ones++;
		}
		else if (tmp == 0) {
			zeros++;
		}
		else {
			neg.push(tmp);
		}
	}

	int sum = 0;
	int data1, data2;

	while (pos.size() > 1) {
		data1 = pos.top();
		pos.pop();
		data2 = pos.top();
		pos.pop();
		sum += (data1 * data2);
	}

	if (pos.size() == 1) {
		sum += pos.top();
	}

	while (neg.size() > 1) {
		data1 = neg.top();
		neg.pop();
		data2 = neg.top();
		neg.pop();
		sum += (data1 * data2);
	}

	if (neg.size() == 1 && zeros > 0) {
		sum += ones;
		cout << sum;
		return 0;
	}
	else if (neg.size()==0) {
		sum += ones;
		cout << sum;
		return 0;
	}
	else {
		sum += neg.top();
		sum += ones;
		cout << sum;
		return 0;
	}
}