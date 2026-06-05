#include <iostream>
#include <tuple>
#include <vector>
#include <limits.h>

using namespace std;

typedef tuple<int, int, int> edge;
vector<edge> graph;
vector<long long> distances;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, A, B, C;
	int i, j;

	cin >> N >> M;
	distances.resize(N+1, 0);
	graph.resize(M + 1);

	for (i = 2; i <= N; i++) {
		distances[i] = LLONG_MAX;
	}
	
	int a, b, c;
	for (i = 1; i <= M; i++) {
		cin >> a >> b >> c;
		graph[i] = make_tuple(a, b, c);
	}

	int start;
	int end;
	int weight;
	long long tmp;
	for (i = 1; i <= N - 1; i++) {
		for (j = 1; j <= M; j++) {
			start = get<0>(graph[j]);
			end = get<1>(graph[j]);
			weight = get<2>(graph[j]);

			tmp = weight + distances[start];
			if (distances[start]!=LLONG_MAX && (distances[end] > tmp)) distances[end] = tmp;
		}
	}

	for (j = 1; j <= M; j++) {
		start = get<0>(graph[j]);
		end = get<1>(graph[j]);
		weight = get<2>(graph[j]);

		tmp = weight + distances[start];
		if (distances[start] != LLONG_MAX && (distances[end] > tmp)) {
			cout << "-1";
			return 0;
		}
	}

	for (i = 2; i <= N; i++) {
		if(distances[i] != LLONG_MAX) cout << distances[i] << "\n";
		else cout << "-1\n";
	}
}