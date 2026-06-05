#include <iostream>
#include <string>
using namespace std;

int recursion(const string& s, int l, int r, int& cnt) {
    while (l < r) {
        cnt++;
        if (s[l] != s[r]) return 0;
        l++;
        r--;
    }
    cnt++;
    return 1;
}

int isPalindrome(const string& s, int& cnt) {
    return recursion(s, 0, s.size() - 1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string word;
        cin >> word;
        int cnt = 0;
        cout << isPalindrome(word, cnt) << " " << cnt << "\n";
    }
}
