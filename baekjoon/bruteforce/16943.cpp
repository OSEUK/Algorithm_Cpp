/**
 * BAEKJOON ONLINE JUDGE
 * 문제명 : 숫자 재배치
 * 난이도 : SILVER I
 */

#include <iostream>
#include <vector>
using namespace std;

int A, B;
int result = -1;
vector<bool> visited;

void backtrack(string s, string curr) {
	
	if (!curr.empty() && curr.at(0) == '0') return;
	if (s.length() == curr.length()) {
		int c = stoi(curr);
		if (c < B) {
			result = max(c, result);
			return;
		}
	}

	for (int i = 0; i < s.length(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			backtrack(s, curr + s.at(i));
			visited[i] = false;
		}
	}

	return;
}
int main(void) {
	
	cin >> A >> B;
	
	string s = to_string(A);
	visited.resize(s.length());

	backtrack(s, "");

	cout << result << "\n";
}