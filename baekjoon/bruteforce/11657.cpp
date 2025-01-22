#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;

struct Edge {
	int from, to, time;
};

vector<Edge> edges;
vector<long long> dist(501, LLONG_MAX);

int main(void) {
	
	cin >> N >> M;
	
	edges.resize(M);
	
	for (int i = 0; i <= M; i++) {
		cin >> edges[i].from >> edges[i].to >> edges[i].time;
	}
	
	dist[1] = 0;
	bool hasNegativeCycle = false;

	for (int i = 1; i <= N; i++) {
		for (const Edge& edge : edges) {
			int from = edge.from;
			int to = edge.to;
			int time = edge.time;

			if (dist[from] == LLONG_MAX) continue;
			
			if (dist[to] > dist[from] + time) {
				dist[to] = dist[from] + time;

				if (i == N) {
					hasNegativeCycle = true;
					break;
				}
			}
		}
	}

	if (hasNegativeCycle) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == LLONG_MAX) {
				cout << -1 << '\n';
			}
			else {
				cout << dist[i] << '\n';
			}
		}
	}

	return 0;
	
	
}