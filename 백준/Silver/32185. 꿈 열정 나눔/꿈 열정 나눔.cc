#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int v0, p0, s0;
    cin >> v0 >> p0 >> s0;
    int standard = v0 + p0 + s0;

    int v, p, s;
    vector<pair<int, int>> candidates;  

    for (int i = 1; i <= n; i++) {
        cin >> v >> p >> s;
        int sum = v + p + s;
        if (sum <= standard) {
            candidates.push_back({ sum, i });
        }
    }

    sort(candidates.begin(), candidates.end(), greater<>());

    cout << "0 ";
    for (int i = 0; i < m - 1 && i < candidates.size(); i++) {
        cout << candidates[i].second << " ";
    }

    return 0;
}
