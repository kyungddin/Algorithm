#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int i, j;
	long long x;

	vector<int> A;
	int cnt;
	for (i = 0; i < n; i++) {
		cin >> x;
		A.push_back(x);
	}

	deque<long long> B;
	for (i = 0; i < n; i++) {
		cin >> x;
		if (A[i] == 0) {
			B.push_back(x);
		}
		else {
			continue;
		}
	}

	int m;
	cin >> m;

	vector<long long> C;
	for (i = 0; i < m; i++) {
		cin >> x;
		C.push_back(x);
	}

	for (i = 0; i < m; i++) {
		B.push_front(C[i]);
		cout << B.back() << " ";
		B.pop_back();
	}
}