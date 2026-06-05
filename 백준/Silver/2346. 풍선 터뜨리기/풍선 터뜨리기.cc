#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> arr;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr.push_back({ i, x });
    }

    int idx = 0;
    while (!arr.empty()) {
        cout << arr[idx].first << " "; 

        int move = arr[idx].second; 
        arr.erase(arr.begin() + idx); 

        if (arr.empty()) break;

        if (move > 0) {
            idx = (idx + move - 1) % (int)arr.size();
        }
        else {
            idx = (idx + move) % (int)arr.size();
            if (idx < 0) idx += arr.size();
        }
    }
}
