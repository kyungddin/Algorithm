#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	cin >> S;

	char s = S.front();
	char f = S.back();

	int cnt = 0;
	int i;

	for (i = 0; i < S.size(); i++) {
		if (S[i] != s) {
			cnt++;
			while (S[i] != s && i!=S.size()) {
				i++;
			}
		}
	}

	cout << cnt;
	return 0;
}