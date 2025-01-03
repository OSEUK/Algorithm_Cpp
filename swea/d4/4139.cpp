
#include<iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, A, B, C, D;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool inRange(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < N;
}

int bfs(const vector<vector<int>>& map){
    queue<tuple<int, int, int>> q;
    q.push({A, B, 0});

    vector<vector<bool>> visited(N, vector<bool>(N));
    visited[A][B] = true;

    while (!q.empty()){
        int x, y, time;
        tie(x, y, time) = q.front();
        q.pop();

        if (x == C && y == D) return time;

        for (int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!inRange(nx, ny) || map[nx][ny] == 1 || visited[nx][ny]) continue;

            if (map[nx][ny] == 2 && time % 3 != 2){
                q.push({x, y, time + 1}); 
                continue;
            }

            q.push({nx, ny, time + 1});
            visited[nx][ny] = true;
        }
    }

    return -1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;

        // 수영장 초기화
        vector<vector<int>> map(N, vector<int>(N));    
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cin >> map[i][j];
            }
        }

        cin >> A >> B;  // 시작 위치
        cin >> C >> D;  // 도착 위치

        cout << "#" << test_case << " " << bfs(map) << "\n";
	}

	return 0;
}