#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

int main(void){

    cin >> N >> M;
    
    vector<vector<int>> graph(N + 1);
    vector<int> inDegree(N + 1);
    
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        inDegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 1; i <= N; i++){
        if (inDegree[i] == 0){
            pq.push(i);
        }
    }

    while (!pq.empty()){
        int n = pq.top();
        pq.pop();

        cout << n << ' ';
        for (int num : graph[n]){
            inDegree[num]--;
            if (inDegree[num] == 0){
                pq.push(num);
            }
        }
    }

    return 0;
}