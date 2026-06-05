#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; ++tc) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "#\n";
        }
        else {
            cout << string(n, '#') << "\n";
            for (int i = 0; i < n - 2; ++i) {
                cout << '#' << string(n - 2, 'J') << "#\n";
            }
            cout << string(n, '#') << "\n";
        }
        if (tc != T - 1) {
            cout << "\n";
        }
    }

    return 0;
}
