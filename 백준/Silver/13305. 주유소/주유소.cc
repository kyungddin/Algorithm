#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> dist(n - 1); 
    vector<long long> cost(n);

    for (int i = 0; i < n - 1; ++i) {
        cin >> dist[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    long long total_cost = 0;
    long long min_cost = cost[0];

    for (int i = 0; i < n - 1; ++i) {
        if (cost[i] < min_cost) {
            min_cost = cost[i]; 
        }
        total_cost += min_cost * dist[i];
    }

    cout << total_cost;
}
