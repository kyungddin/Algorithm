#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> visit(100001, 0);
vector<pair<int, int>> adj[100001];
queue<pair<int, int>> q;
vector<int> d(100001, 0);

void BFS(int num) {
    visit[num] = true;
    q.push({ num, 0 });

    while (!q.empty()) {
        int cur = q.front().first;
        q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i].first;
            int weight = adj[cur][i].second;

            if (!visit[next]) {
                visit[next] = true;
                d[next] = d[cur] + weight;
                q.push({ next, 0 }); 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    cin >> v;

    int a, b, c;
    for (int i = 0; i < v; i++) {
        cin >> a;
        while (true) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            adj[a].push_back({ b, c });
        }
    }

    BFS(1);

    int idx = 1, maxDist = 0;
    for (int i = 1; i <= v; i++) {
        if (d[i] > maxDist) {
            maxDist = d[i];
            idx = i;
        }
    }

    fill(d.begin(), d.end(), 0);
    fill(visit.begin(), visit.end(), 0);
    while (!q.empty()) q.pop();

    BFS(idx);

    maxDist = 0;
    for (int i = 1; i <= v; i++) {
        if (d[i] > maxDist) {
            maxDist = d[i];
        }
    }

    cout << maxDist << "\n";
}
