#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int i;
	unordered_set<string> h_set1;
	unordered_set<string> h_set2;
	string name;

	for (i = 0; i < n; i++) {
		cin >> name;
		h_set1.insert(name);
	}

	for (i = 0; i < m; i++) {
		cin >> name;
		h_set2.insert(name);
	}

	vector<string> result(h_set1.begin(), h_set1.end());
	vector<string> total;

	int count = 0;
	for (i = 0; i < n; i++) {
		if (h_set2.find(result[i]) != h_set2.end()) {
			count++;
			total.push_back(result[i]);
		}
	}

	sort(total.begin(), total.end());

	cout << count << "\n";
	for (i = 0; i < total.size(); i++) {
		cout << total[i] << "\n";
	}
}