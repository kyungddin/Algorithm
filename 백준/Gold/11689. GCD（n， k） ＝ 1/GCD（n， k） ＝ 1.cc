#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long int n;
	cin >> n;

	long int result = n;

	for (long int i=2; i<=sqrt(n); i++){
		if (n % i == 0) {
			result = result - result / i;
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		result = result - result / n;
	}

	cout << result;
}