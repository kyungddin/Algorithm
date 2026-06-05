#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<string, int> map;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map.clear();

	int i;
	int n;
	string word;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> word;
		map[word]++;
	}

	int max = 0;
	string best = "";

	for (auto& p : map) {
		if (p.second > max) {
			max = p.second;
			best = p.first;
		}
		else if (p.second == max && p.first < best) {
			best = p.first;
		}
	}

	cout << best;
}