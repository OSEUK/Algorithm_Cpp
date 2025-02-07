#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;
using pi = pair<int, int>;

int n, s, e;

vector<int> visited;
vector<vector<pi>> graph;

vector<pi> prev_dist;

int result = 0;
void dfs(int curr, int goal, int dist) {
	if (curr == goal) {
		result = dist;
		return;
	}

	visited[curr] = 1;
	for (pi next : graph[curr]) {
		if (visited[next.first]) continue;

		prev_dist[next.first] = { curr, next.second };
		dfs(next.first, goal, dist + next.second);
	}

	visited[curr] = 0;

	
}
int main(void){
	cin >> n >> s >> e;
	
	graph.resize(n + 1);
	visited.resize(n + 1, 0);
	prev_dist.resize(n + 1, { 0, 0 });
	for (int i = 0; i < n - 1; i++) {
		int start, end, dist;

		cin >> start >> end >> dist;
		graph[start].push_back({ end, dist });
		graph[end].push_back({ start, dist });
	
	}
	
	dfs(s, e, 0);
	int idx = e;
	int max_dist = 0;
	while (prev_dist[idx].first != 0) {
		max_dist = max(max_dist, prev_dist[idx].second);

		idx = prev_dist[idx].first;
	}

	
	cout <<  result - max_dist;
}