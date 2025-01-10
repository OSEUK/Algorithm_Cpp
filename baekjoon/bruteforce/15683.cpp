/**
 * BAEKJOON ONLINE JUDGE
 * 문제명 : 감시
 * 난이도 : GOLD III
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
int result = INT_MAX;
vector<vector<int>> map;
vector<pair<int, int>> cctvs;

// 상 하 좌 우 
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// cctv의 숫자 별 감시 범위 
const vector<vector<vector<int>>> directions = {
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 1}, {2, 3}},
    {{0, 2}, {1, 3}, {0, 3}, {1, 2}},
    {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}},
    {{0, 1, 2, 3}}
};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

// 해당 cctv가 범위 탐색색
void watch(int x, int y, const vector<int>& dirs, vector<pair<int, int>>& changed){
    
    for (int dir : dirs){
        int nx = x, ny = y;

        while (true){
            nx += dx[dir];
            ny += dy[dir];
            if (!inRange(nx, ny) || map[nx][ny] == 6) break;
            
            if (map[nx][ny] == 0){
                map[nx][ny] = -1;
                changed.push_back({nx, ny});
            }
        }
    }
}

// cctv별로 탐색을 진행행
void dfs(int depth){

    // cctv개수만큼 탐색하였을 때 0의 개수 세기기
    if (depth == cctvs.size()){
        int cnt = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (map[i][j] == 0) cnt++;
            }
        }

        result = min(cnt, result);
        return;
    }

    
    int x = cctvs[depth].first;
    int y = cctvs[depth].second;
    int type = map[x][y];

    for (const vector<int>& dirs : directions[type]){
        vector<pair<int, int>> changed;
        watch(x, y, dirs, changed);

        // 다음 cctv로 진입입
        dfs(depth + 1);
        
        // 백트래킹
        for (pair<int, int>& p : changed){
            map[p.first][p.second] = 0;
        }
    }
}

int main(void){
    
    // input

    cin >> N >> M;

    map.resize(N, vector<int>(M));   

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];

            if (map[i][j] >= 1 && map[i][j] <= 5){
                cctvs.push_back({i, j});
            }
        }
    } 

    // solution
    dfs(0);

    cout << result << "\n";
}

