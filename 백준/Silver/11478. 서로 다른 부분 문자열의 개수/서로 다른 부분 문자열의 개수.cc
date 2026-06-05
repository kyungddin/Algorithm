#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

unordered_map<string, bool> map;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	string word;
	string tmp;

	cin >> word;
	
	for (i = 1; i <= word.size(); i++) {
		for (j = 0; j < word.size(); j++) {
			if (j + i > word.size()) continue;
			tmp = word.substr(j, i);
			map[tmp] = 1;
		}
	}

	cout << map.size();
}