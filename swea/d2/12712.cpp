#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;

bool inRange(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

int sprayPlus(const vector<vector<int>>& map, int x, int y){
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    int sum = map[x][y];

    for (int i = 1; i < M; i++){
        for (int j = 0; j < 4; j++){
            int nx = x + i*dx[j];
            int ny = y + i*dy[j];

            if (!inRange(nx, ny)) continue;
            
            sum += map[nx][ny];
        }   
    }

    return sum;
}

int sprayX(const vector<vector<int>>& map, int x, int y){
    int dx[4] = {-1, 1, -1, 1};
    int dy[4] = {-1, -1, 1, 1};
    
    int sum = map[x][y];

    for (int i = 1; i < M; i++){
        for (int j = 0; j < 4; j++){
            int nx = x + i*dx[j];
            int ny = y + i*dy[j];

            if (!inRange(nx, ny)) continue;
            
            sum += map[nx][ny];
        }   
    }

    return sum;
}
int main(int argc, char** argv){
    int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        
        // N = 가로세로크기, M = 스프레이의 세기
        cin >> N >> M;

        // 2차원 배열 선언
        vector<vector<int>> map(N, vector<int>(N));

        // 배열 초기화
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cin >> map[i][j];
            }
        }

        int result = INT_MIN;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                result = max(result, sprayPlus(map, i, j));
                result = max(result, sprayX(map, i, j));
            }
        }        
        
        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}