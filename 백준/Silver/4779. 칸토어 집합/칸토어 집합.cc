#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string word;

void k_set(string& w, int from, int to, int size);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n=0;
	int x;
	int i;
	int l;
	
	while (cin >> n) {
		word.clear();
		x = pow(3, n);
		word.resize(x);

		for (i = 0; i < x; i++) {
			word[i] = '-';
		} // 칸토어 초기 설정
		
		k_set(word, 0, x, x);

		for (i = 0; i < x; i++) {
			cout << word[i];
		}
		cout << "\n";
	}
}

void k_set(string& w, int from, int to, int size)
{
	if (size == 1) return;

	int len = size / 3;

	for (int i = from+len; i < from+len+len; i++) {
		word[i] = ' ';
	}

	k_set(w, from, from+len, len);
	k_set(w, from+len+len, to, len);
}