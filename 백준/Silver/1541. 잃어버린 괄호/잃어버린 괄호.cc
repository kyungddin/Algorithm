#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char element);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int answer = 0;
	int sum = 0;
	string equation;
	vector<string> split_str;
	vector<string> tmp;

	cin >> equation;

	split_str = split(equation, '-');

	for (i = 0; i < split_str.size(); i++) {
		tmp = split(split_str[i], '+');
		for (j = 0; j < tmp.size(); j++) {
			sum += stoi(tmp[j]);
		}
		if (i == 0) {
			answer += sum;
		}
		else {
			answer -= sum;
		}
		sum = 0;
		tmp.clear();
	}

	cout << answer;
}

vector<string> split(string str, char element) {
	stringstream mystream(str);
	string temp;
	vector<string> result;

	while (getline(mystream, temp, element)) {
		result.push_back(temp);
	}

	return result;
}