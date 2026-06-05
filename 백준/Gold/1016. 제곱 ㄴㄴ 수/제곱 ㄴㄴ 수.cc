#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int min, max;
	cin >> min >> max;
	vector<bool> arr(max - min + 1);

	for (long long int i = 2; i * i <= max; i++) {
		long int pow = i * i;
		long int idx = min / pow;

		if (min % pow != 0) {
			idx++;
		}

		for (long long int j = idx; pow * j <= max; j++) {
			arr[(int)((j * pow) - min)] = true;
		}
	}

	int count = 0;

	for (int i = 0; i <= max - min; i++) {
		if (!arr[i]) count++;
	}

	cout << count;
}