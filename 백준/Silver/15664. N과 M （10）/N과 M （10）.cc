#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
vector<int> result;

void DFS(int start, int depth) {
    if (depth == m) {
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;  

    for (int i = start; i < n; ++i) {
        if (nums[i] == prev) continue;  
        prev = nums[i];

        result.push_back(nums[i]);
        DFS(i + 1, depth + 1); 
        result.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());  

    DFS(0, 0);

    return 0;
}
