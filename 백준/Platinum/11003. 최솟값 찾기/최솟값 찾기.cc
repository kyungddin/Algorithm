#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	int i;
	int tmp;

	deque<node> arr;

	cin >> N >> L;

	for (i = 0; i < N; i++) {
		cin >> tmp;
		while (arr.size() && arr.back().first > tmp) {
			arr.pop_back();
		}

		arr.push_back(node(tmp, i));

		while (arr.front().second <= i - L) {
			arr.pop_front();
		}

		cout << arr.front().first << " ";
	}
}