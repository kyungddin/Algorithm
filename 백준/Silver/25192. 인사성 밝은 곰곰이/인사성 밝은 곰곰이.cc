#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, n;
	int cnt=0;
	string tmp;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == "ENTER") q.clear();
		else {
			if (q[tmp] == true) continue;
			else {
				q[tmp] = true;
				cnt++;
			}
		}
	}

	cout << cnt;
}