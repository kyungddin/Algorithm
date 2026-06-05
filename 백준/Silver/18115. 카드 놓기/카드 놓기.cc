#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tmp;
vector<int> cmd;

deque<int> result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int i;
	for (i = n; i > 0; i--) {
		tmp.push_back(i);
	}
	
	int x;
	for (i = 0; i < n; i++) {
		cin >> x;
		cmd.push_back(x);
	}

	for (i = n-1; i >=0; i--) {
		x = cmd[i];

		if (x == 1) {
			result.push_front(tmp[i]); 
		}
		else if (x==2){
			if (result.size() == 1) result.push_back(tmp[i]);
			else {
				result.push_front(tmp[i]);
				swap(result[0], result[1]);
			}
		}
		else if (x == 3) {
			result.push_back(tmp[i]);
		}
	}

	for (i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}