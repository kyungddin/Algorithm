#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> meetings(n);

    for (int i = 0; i < n; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    sort(meetings.begin(), meetings.end(), compare);

    int count = 1;
    int finish = meetings[0].second;

    for (int i = 1; i < n; i++) {
        if (meetings[i].first >= finish) {
            count++;
            finish = meetings[i].second;
        }
    }

    cout << count;
    return 0;
}
