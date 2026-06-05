#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, int> dict;
	string pokemon;
	vector<string>arr;
	int i;
	
	for (i = 0; i < n; i++) {
		cin >> pokemon;
		dict[pokemon]=i+1;
		arr.push_back(pokemon);
	}

	int num;
	for (i = 0; i < m; i++) {
		cin >> pokemon;
		if (pokemon[0] >= '0' && pokemon[0] <= '9') {
			num = stoi(pokemon);
			num--;
			cout << arr[num] << "\n";
		}
		else {
			cout << dict[pokemon] << "\n";
		}
	}
}