#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi = pair<int, int>;
using ll = long long;

#define MAX_LOG 16

int N, M;
vector<vector<pi>> graph;
vector<vector<int>> parent;
vector<int> depth;
vector<ll> dist;

void dfs(int curr, ll d, int pre, int dep){
    dist[curr] = d;
    parent[0][curr] = pre;
    depth[curr] = dep;
    
    for (pi next : graph[curr]){
        int n = next.first;
        int dt = next.second;
        
        if (n == pre) continue;
        
        dfs(n, d + dt, curr, dep + 1);
    }
}

void build(){
    for (int k = 1; k < MAX_LOG; k++){
        for (int node = 1; node <= N; node++){
            int ancestor = parent[k-1][node];

            if (ancestor == 0) continue;
            
            parent[k][node] = parent[k-1][ancestor];
        }
    }
}

ll find(int u, int v){
    ll du = dist[u];
    ll dv = dist[v];

    // u를 v보다 깊게 설정
    if (depth[u] < depth[v])
        swap(u, v);

    // u와 v의 높이를 일치시킴
    if (depth[u] != depth[v]){
        int diff = depth[u] - depth[v];

        for (int k = MAX_LOG - 1; k >= 0; k--){
            if (diff & (1 << k)) u = parent[k][u];
        }
    }
    
    // 공통 조상 찾을 시, 거리 return
    if (u == v) {
        return du + dv - dist[u] * 2;
    }

    // 탐색
    for (int k = MAX_LOG - 1; k >= 0; k--){
        if (parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }

    u = parent[0][u];
    
    return du + dv - dist[u] * 2; 
}


int main(void){
    
    cin >> N;
    // initialize
    graph.resize(N + 1);
    parent.resize(MAX_LOG + 1, vector<int>(N + 1, 0));
    dist.resize(N + 1, 0);
    depth.resize(N + 1, 0);

    // graph setting
    for (int i = 0; i < N - 1; i++){
        int s, e, d;
        cin >> s >> e >> d;

        graph[s].push_back({e, d});
        graph[e].push_back({s, d});
    }

    // sparse table build
    dfs(1, 0, 0, 0);
    build();

    // query
    cin >> M;
    while (M--){
        int u, v;
        cin >> u >> v;
        
        cout << find(u, v) << "\n";
    }
}