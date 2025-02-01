// SWEA D3 10726 이진수 표현


#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, M;
        cin >> N >> M;
        
        if ((M & ((1 << N) - 1)) + 1 == (1 << N)){
            cout << "#" << test_case << " ON\n";
            continue;
        }

        cout << "#" << test_case << " OFF\n";
	}

	return 0;
}