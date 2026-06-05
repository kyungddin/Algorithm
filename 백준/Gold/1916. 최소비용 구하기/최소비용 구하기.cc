#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[20001];
vector<int> dist(20001);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    dist.resize(V + 1);
    fill(dist.begin(), dist.end(), 999999999);

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }


    int start_node, end_node;
    cin >> start_node >> end_node;

    dist[start_node] = 0;

    q.push(make_pair(0, start_node));

    while (!q.empty()) {
        int curr_dist = q.top().first;
        int u = q.top().second;
        q.pop();

        if (curr_dist > dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push(make_pair(dist[v], v));
            }
        }
    }

    cout << dist[end_node];

}
