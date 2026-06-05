#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	int x;
	string command;

	int i;
	int arr[21] = {};

	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> command;

		if (command == "add") {
			cin >> x;
			arr[x] = 1;
		}
		else if (command == "remove") {
			cin >> x;
			arr[x] = 0;
		}
		else if (command == "check") {
			cin >> x;
			cout << arr[x] << "\n";
		}
		else if (command == "toggle") {
			cin >> x;
			if (arr[x] == 0) arr[x] = 1;
			else arr[x] = 0;
		}
		else if (command == "all") {
			for (int j = 1; j <= 20; j++) arr[j] = 1;
		}
		else if (command == "empty") {
			for (int j = 1; j <= 20; j++) arr[j] = 0;
		}
	}
}