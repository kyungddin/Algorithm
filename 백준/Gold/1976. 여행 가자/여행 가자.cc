#include <iostream>
#include <vector>

using namespace std;

void unionfunc(int a, int b);
int find(int num);

vector<int> arr;
vector<int> result;
int city[201][201] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int i, j;
	int tmp;

	arr.resize(n + 1);
	for (i = 1; i <= n; i++) {
		arr[i] = i;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> tmp;
			city[i][j] = tmp;
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (city[i][j] == 1) {
				unionfunc(i, j);
			}
		}
	}

	for (i = 0; i < m; i++) {
		cin >> tmp;
		result.push_back(find(tmp));
	}

	for(i=0; i<result.size()-1; i++){
		if (result[i] == result[i + 1]) continue;
		else {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		arr[b] = a;
	}
}

int find(int num) {
	if (num == arr[num]) return num;
	else {
		return arr[num] = find(arr[num]);
	}
}