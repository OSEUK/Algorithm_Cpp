
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, B;
int result;
vector<bool> visited(20);

void find(vector<int>& heights, int sum, int idx){
	if (sum >= result) return;

	if (sum >= B){
		result = sum;
		return;
	}

	if (idx == N) return;
	
	// 선택
	find(heights, sum + heights[idx], idx + 1);

	// 미선택
	find(heights, sum, idx + 1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> B;
		
		vector<int> heights(N);
		for (int i = 0; i < N; i++) cin >> heights[i];

		result = INT_MAX;
		find(heights, 0, 0);

		cout << "#" << test_case << " " << result - B << "\n";
	}
	return 0;
}