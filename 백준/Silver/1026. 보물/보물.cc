#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i;
	cin >> n;

	vector<int> a;
	vector<pair<int, int>> b;
	vector<int> c;
	vector<int> idx;
	
	int tmp;
	for (i = 0; i < n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}

	for (i = 0; i < n; i++) {
		cin >> tmp;
		b.push_back(pair<int, int>(tmp, i));
	}

	for (i = 0; i < n; i++) {
		c.push_back(b[i].first);
	}

	sort(b.begin(), b.end(), greater<>());

	vector<int> d (n);

	sort(a.begin(), a.end());

	for (i = 0; i < n; i++) {
		d[b[i].second] = a[i];
	}

	int sum = 0;

	for (i = 0; i < n; i++) {
		sum += (d[i] * c[i]);
	}

	cout << sum;
}