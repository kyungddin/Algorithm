#include <iostream>
#include <vector>

using namespace std;

int n;

bool isPrime(int num) {
	int i;
	for (i = 2; i < num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void DFS(int num, int length) {
	if (length == n) {
		if (isPrime(num) == true) {
			cout << num << "\n";
		}
	}
		for (int i = 1; i < 10; i++) {
			if (i % 2 == 0) continue;
			if (isPrime(num * 10 + i) == true) {
				DFS(num * 10 + i, length+1);

			}
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
 	DFS(7, 1);
}