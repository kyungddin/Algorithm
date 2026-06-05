#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n, k;

	cin >> n >> k;

	int i, tmp;
	vector<int> arr;
	for (i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	cout << arr[k - 1];
}