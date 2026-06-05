#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int i;
	unordered_set<string> h_set;
	string word;

	for (i = 0; i < n; i++) {
		cin >> word;
		h_set.insert(word);
	}

	int count=0;
	for (i = 0; i < m; i++) {
		cin >> word;
		count += h_set.count(word);
	}

	cout << count;
}