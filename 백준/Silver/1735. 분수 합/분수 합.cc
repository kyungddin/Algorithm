#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int a, b, c, d;

	cin >> a >> b;
	cin >> c >> d;

	int e, f;

	if (b != d) {
		e = b * d;
		f = (a * d) + (b * c);
	}
	else {
		e = b;
		f = a + c;
	}

	int result = gcd(e, f);

	e /= result;
	f /= result;

	cout << f << " " << e;
}