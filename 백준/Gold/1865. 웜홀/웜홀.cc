#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

typedef tuple <int, int, int> edge;
vector<edge> graph;
vector<long long> distances;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC, N, M, W;
	int S, E, T;

	int i, j, k;
	int cnt;

	cin >> TC;
	for (i = 0; i < TC; i++) {
		graph.clear();
		distances.clear();
		cnt = 0;

		cin >> N >> M >> W;
		distances.resize(N + 1,0);

		for (j = 0; j < M; j++) {
			cin >> S >> E >> T;
			graph.push_back(make_tuple(S, E, T));
			cnt++;
			graph.push_back(make_tuple(E, S, T));
			cnt++;
		}

		for (j = 0; j < W; j++) {
			cin >> S >> E >> T;
			graph.push_back(make_tuple(S, E, -T));
			cnt++;
		}

		for (j = 1; j < N; j++) {
			for (k = 0; k < cnt; k++) {
				edge tmp = graph[k];
				int start = get<0>(tmp);
				int end = get<1>(tmp);
				int weight = get<2>(tmp);
				if (distances[end] > distances[start] + weight) {
					distances[end] = distances[start] + weight;
				}
			}
		}

		bool checker = false;

		for (k = 0; k < cnt; k++) {
			edge tmp = graph[k];
			int start = get<0>(tmp);
			int end = get<1>(tmp);
			int weight = get<2>(tmp);
			if (distances[end] > distances[start] + weight) {
				checker = true;
				break;
			}
		}

		if (checker == true) cout << "YES\n";
		else cout << "NO\n";
	}
}