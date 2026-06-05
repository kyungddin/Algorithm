#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word1;
	string word2;

	cin >> word1;
	cin >> word2;

	int a = word1.size();
	int b = word2.size();

	if (a >= b) cout << "go";
	else cout << "no";
}