#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_LOG 18
using namespace std;

using ll = long long;
using pi = pair<int, int>;

int N, K;
vector<vector<pi>> graph;
vector<vector<int>> par;
vector<int> depth;
vector<vector<int>> max_dist;
vector<vector<int>> min_dist;

void dfs(int curr, int pre, int dep){
    depth[curr] = dep;
    par[0][curr] = pre;
    
    for (pi next : graph[curr]){
        int node = next.first;
        int dist = next.second;
        
        if (node == pre) continue;
        
        max_dist[0][node] = dist;
        min_dist[0][node] = dist;

        dfs(node, curr, dep + 1);
    }
}

void build(){
    for (int k = 1; k < MAX_LOG; k++){
        for (int n = 1; n <= N; n++){
            int ancestor = par[k-1][n];
            
            if (ancestor == 0) continue;
            
            par[k][n] = par[k-1][ancestor];
            max_dist[k][n] = max(max_dist[k-1][n], max_dist[k-1][ancestor]);
            min_dist[k][n] = min(min_dist[k-1][n], min_dist[k-1][ancestor]);
        }
    }
}

pi find(int u, int v){
    // u를 더 깊게
    if (depth[u] < depth[v]){
        swap(u, v);
    }
    
    // 높이 맞추기
    int diff = depth[u] - depth[v];

    int min_res = INT_MAX;
    int max_res = INT_MIN;
    for (int k = MAX_LOG - 1; k >= 0; k--){
        if (diff & (1<<k)) {
            
            min_res = min(min_res, min_dist[k][u]);
            max_res = max(max_res, max_dist[k][u]);
            u = par[k][u];
        }
    }

    if (u == v){
        return {min_res, max_res};
    }
    // 탐색
    
    for (int k = MAX_LOG - 1; k >= 0; k--){
        if (par[k][u] != par[k][v]){
            
            min_res = min(min_res, min(min_dist[k][u], min_dist[k][v]));
            max_res = max(max_res, max(max_dist[k][u], max_dist[k][v]));
            u = par[k][u];
            v = par[k][v];
        }
    }

    min_res = min(min_res, min(min_dist[0][u], min_dist[0][v]));
    max_res = max(max_res, max(max_dist[0][u], max_dist[0][v]));

    return {min_res, max_res};
    
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    graph.resize(N + 1);
    par.resize(MAX_LOG, vector<int>(N + 1, 0));
    depth.resize(N + 1);
    max_dist.resize(MAX_LOG, vector<int>(N + 1, 0));
    min_dist.resize(MAX_LOG, vector<int>(N + 1, 0));

    for (int i = 0; i < N-1; i++){
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    cin >> K;
    dfs(1, 0, 0);
    build();

    while (K--){
        int D, E;
        cin >> D >> E;

        pi res = find(D, E);
        
        cout << res.first << " " << res.second << "\n";
    }
}