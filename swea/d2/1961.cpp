#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;
        
        vector<vector<int>> arr(N, vector<int>(N));
        vector<vector<int>> arr90(N, vector<int>(N));
        vector<vector<int>> arr180(N, vector<int>(N));
        vector<vector<int>> arr270(N, vector<int>(N));

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                arr90[i][j] = arr[N-1-j][i]; 
            }
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                arr180[i][j] = arr90[N-1-j][i];
            }
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                arr270[i][j] = arr180[N-1-j][i];
            }
        }
        
        cout << "#" << test_case << "\n";

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cout << arr90[i][j];
            }
            cout << " ";
            for (int j = 0; j < N; j++){
                cout << arr180[i][j];
            }
            cout << " ";
            for (int j = 0; j < N; j++){
                cout << arr270[i][j];
            }
            
            cout << "\n";
        }
	}

	return 0;
}