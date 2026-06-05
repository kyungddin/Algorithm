#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, bool> q = {};
unordered_set<string> r;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, n;
	int cnt=0;
	string tmp1;
	string tmp2;
	string tmp;

	cin >> n;

	q["ChongChong"] = 1;

	for (i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2;
		r.insert(tmp1);
		r.insert(tmp2);

		if (q[tmp1] == 1 || q[tmp2] == 1) {
			q[tmp2] = 1;
			q[tmp1] = 1;
		}
	}

	vector<string> p(r.begin(), r.end());

	for (i = 0; i < p.size(); i++) {
		if (q[p[i]] == 1) cnt++;
	}

	cout << cnt;
}