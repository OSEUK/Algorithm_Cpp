#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N;

int main(void){

    cin >> N;

    vector<vector<int>> graph(N + 1);
    vector<int> inDegree(N + 1);
    vector<int> times(N + 1);
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++){
        int turn, time;
        cin >> time >> turn;

        times[i] = time;

        for (int t = 0; t < turn; t++){
            int num;
            cin >> num;
            graph[num].push_back(i);
            inDegree[i]++;
        }     
    }       
    
    queue<int> q;
    for (int i = 1; i <= N; i++){
        if (inDegree[i] == 0){
            q.push(i);
            dp[i] = times[i];
        }
    }


    while (!q.empty()){
        int n = q.front();
        q.pop();
        
        for (int next : graph[n]){
            inDegree[next]--;
            dp[next] = max(dp[next], dp[n] + times[next]);
            if (inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++){
        result = max(result, dp[i]);
    }

    cout << result  << "\n";
}