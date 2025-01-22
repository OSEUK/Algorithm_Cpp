#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;

vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void union_nodes(int x, int y) {
	int a = find(x);
	int b = find(y);

	if (a > b) parent[a] = b;
	else parent[b] = a;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V >> E;

	// 부모 초기화
	parent.resize(V + 1);
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	vector < pair<int, pair<int, int>>> edges;

	for (int i = 0; i < E; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;

		edges.push_back({ cost, {a, b} });
	}

	sort(edges.begin(), edges.end());

	int result = 0;
	int len = 0;

	for (auto edge : edges) {
		int cost = edge.first;
		int a = edge.second.first;
		int b = edge.second.second;

		if (find(a) != find(b)) {
			union_nodes(a, b);
			result += cost;
			len++;
		}

		if (len == V - 1) {
			break;
		}
	}

	cout << result << "\n";
}