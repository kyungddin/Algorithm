#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<int> A, B;
    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        A.insert(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        B.insert(x);
    }

    int answer = 0;
    for (int v : A) {
        if (B.find(v) == B.end()) {
            answer++;
        }
    }

    for (int v : B) {
        if (A.find(v) == A.end()) {
            answer++;
        }
    }

    cout << answer << '\n';
    return 0;
}
