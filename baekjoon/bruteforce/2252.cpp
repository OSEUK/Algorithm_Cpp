#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> inDegree(N+1, 0);   // 진입 차수

    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++){
        if (inDegree[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()){
        int cur = q.front();
        q.pop();

        cout << cur << ' ';

        for (int next : graph[cur]){
            inDegree[next]--;

            if (inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    return 0;
}