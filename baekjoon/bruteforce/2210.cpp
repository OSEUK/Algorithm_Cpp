#include <iostream>
#include <vector>

#define SIZE 5

using namespace std;

vector<vector<int>> map(SIZE, vector<int>(SIZE));
vector<bool> visited(1000000, false);

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int result = 0;

bool inRange(int x, int y) {
	return 0 <= x && x < SIZE && 0 <= y && y < SIZE;
}

void dfs(int x, int y,int curr, int len) {
	if (len == 6) {
		if (!visited[curr]) {
			visited[curr] = true;
			result++;
		}
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		if (!inRange(nx, ny)) continue;

		dfs(nx, ny, curr * 10 + map[nx][ny], len + 1);
	}
}
int main(void) {
	
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			dfs(i, j, map[i][j], 1);
		}
	}

	cout << result << "\n";
}