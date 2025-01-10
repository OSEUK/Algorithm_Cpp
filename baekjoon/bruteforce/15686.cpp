#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M, result = INT_MAX;

vector<vector<int>> map;
vector<pair<int, int>> houses;	// 집 위치
vector<pair<int, int>> chickens;	// 치킨집 위치
vector<pair<int, int>> visited;		// 폐업시키고 남은 치킨집

// 남은 치킨집과의 거리 갱신
int calc_distance() {
	int total_distance = 0;

	for (pair<int, int>& house : houses) {
		int distance = INT_MAX;
		
		for (pair<int, int>& chicken : visited) {
			distance = min(distance, abs(house.first - chicken.first) + abs(house.second - chicken.second));
		}

		total_distance += distance;
	}

	return total_distance;
}


void backtrack(int cnt, int idx) {
	// 치킨집 개수중 M개가 선정되면, 거리계산
	if (cnt >= M) {
		result = min(result, calc_distance());
		return;
	}

	// 백트래킹
	for (int i = idx; i < chickens.size(); i++) {
		visited.push_back(chickens[i]);
		backtrack(cnt + 1, i + 1);
		visited.pop_back();
	}
}

int main(void) {
	
	cin >> N >> M;
	map.resize(N, vector<int>(N));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) houses.push_back({ i, j });
			if (map[i][j] == 2) chickens.push_back({ i, j });
		}
	}

	backtrack(0, 0);

	cout << result << "\n";
}