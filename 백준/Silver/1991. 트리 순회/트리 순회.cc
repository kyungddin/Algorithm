#include <iostream>

char arr[27][2] = {};

using namespace std;

void front_search(char num);
void mid_search(char num);
void back_search(char num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int i;

	cin >> n;
	
	char a, b, c;
	for (i = 0; i < n; i++) {
		cin >> a >> b >> c;

		if (b != '.') arr[a - 'A'][0] = b;
		else arr[a - 'A'][0] = -1;
		if (c!='.') arr[a - 'A'][1] = c;
		else arr[a - 'A'][1] = -1;
	}
	front_search('A');
	cout << "\n";
	mid_search('A');
	cout << "\n";
	back_search('A');
	cout << "\n";
}

void front_search(char num) {
	if(num!=-1) cout << num;
	if(arr[num - 'A'][0]!=-1) front_search(arr[num-'A'][0]);
	if (arr[num - 'A'][1] != -1) front_search(arr[num - 'A'][1]);
}

void mid_search(char num) {
	if (arr[num - 'A'][0] != -1) mid_search(arr[num - 'A'][0]);
	cout << num;
	if (arr[num - 'A'][1] != -1) mid_search(arr[num - 'A'][1]);
}

void back_search(char num) {
	if (arr[num - 'A'][0] != -1) back_search(arr[num - 'A'][0]);
	if (arr[num - 'A'][1] != -1) back_search(arr[num - 'A'][1]);
	cout << num;
}