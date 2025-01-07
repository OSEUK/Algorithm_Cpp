/**
 * BAEKJOON ONLINE JUDGE
 * 문제명 : 캠프 준비비
 * 난이도 : GOLD V
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, L, R, X;
int result = 0;

void find(vector<int>& A, int Amin, int Amax, int cnt,int idx,int sum) {
	if (idx >= N){
    if (cnt >= 2 && sum >= L && sum <= R && Amax - Amin >= X) {
		result++;
	}
        return;
    }
    
   

	find(A, Amin, Amax, cnt, idx + 1, sum);
	find(A, min(A[idx], Amin), max(A[idx], Amax), cnt + 1, idx + 1, sum + A[idx]);

	return;
}
int main(void) {
		
	cin >> N >> L >> R >> X;
	
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	find(A, INT_MAX, INT_MIN, 0, 0, 0);

	cout << result << "\n";
}