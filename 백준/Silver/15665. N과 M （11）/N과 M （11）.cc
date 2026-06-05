#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
vector<int> nums;
vector<int> result;
set<vector<int>> printed;

void DFS(int depth) {
    if (depth == m) {
        if (printed.insert(result).second) { 
            for (int x : result) cout << x << ' ';
            cout << '\n';
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        result.push_back(nums[i]);
        DFS(depth + 1);
        result.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    DFS(0);
    return 0;
}
