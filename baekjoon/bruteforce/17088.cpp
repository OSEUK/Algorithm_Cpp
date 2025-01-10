#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
vector<int> arr;

bool check(int expected, int d) {
	for (int i = 2; i < N; i++) {
		expected += d;
		if (abs(expected - arr[i]) > 1) return false;
	}

	return true;
}

int solve() {
	int result = INT_MAX;
	
	for (int d1 = -1; d1 <= 1; d1++) {
		for (int d2 = -1; d2 <= 1; d2++) {
			int first = arr[0] + d1;
			int second = arr[1] + d2;

			int d = second - first;
			
			if (!check(second, d)) continue;

			int expected = second;
			int changed = (d1 != 0) + (d2 != 0);  // 첫 두 수의 변경 카운트

			for (int i = 2; i < N; i++) {
				expected += d;

				if (abs(expected - arr[i]) == 1) changed++;
			}

			result = min(changed, result);
		}
	}

	return result == INT_MAX ? -1 : result;
}
int main(void) {
	
	cin >> N;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << solve() << "\n";
	
}