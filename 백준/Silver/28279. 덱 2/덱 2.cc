#include <iostream>
#include <deque>

using namespace std;

deque<int> d;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i;
	cin >> n;

	int a, b;
	for (i = 0; i < n; i++) {
		cin >> a;

		if (a == 1) {
			cin >> b;
			d.push_front(b);
		}
		else if (a == 2) {
			cin >> b;
			d.push_back(b);
		}
		else if (a == 3) {
			if (d.size() == 0) cout << "-1" << "\n";
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		}
		else if (a==4) {
			if (d.size() == 0) cout << "-1" << "\n";
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		}
		else if (a == 5) {
			cout << d.size() << "\n";
		}
		else if (a == 6) {
			if (d.empty() == 1) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (a == 7) {
			if (d.size() == 0) cout << "-1" << "\n";
			else {
				cout << d.front() << "\n";
			}
		}
		else if (a == 8) {
			if (d.size() == 0) cout << "-1" << "\n";
			else {
				cout << d.back() << "\n";
			}
		}
	}
}