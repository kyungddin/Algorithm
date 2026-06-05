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

	int n;
	cin >> n;

	int i;
	unordered_set<string> h_set;
	string word;
	string command;

	for (i = 0; i < n; i++) {
		cin >> word >> command;
		if (command == "enter") h_set.insert(word);
		else h_set.erase(word);
	}

	vector<string> result(h_set.begin(), h_set.end());
	sort(result.begin(), result.end(), greater<string>());

	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}