#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;
using pi = pair<int, int>;

int n;

vector<int> visited;
vector<vector<int>> graph;
vector<bool> adapter;
vector<pi> naf;
int answer = 0;

bool dfs(int curr) {
	visited[curr] = 1;
	
	bool needEarly = false;

	for (int next : graph[curr]) {
		if (visited[next]) continue;

		if (!dfs(next)) needEarly = true;
	}

	if (needEarly) {
		adapter[curr] = true;
		answer++;
	}

	return adapter[curr];
}


int main(void){
	
	cin >> n;

	graph.resize(n + 1);
	visited.resize(n + 1, 0);
	adapter.resize(n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	
	dfs(1);

	cout << answer;
	
		

	
}