/**
 * BAEKJOON ONLINE JUDGE
 * 문제명 : 나3곱2
 * 난이도 : GOLD V
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<long long int, pair<int, long long int>> a, pair<int, pair<int, long long int>> b){
    if (a.first == b.first){
        return a.second.first < b.second.first;
    }

    return a.first > b.first;
}

int main(void){
    int n;
    vector<pair<long long int, pair<long long int, long long int>>> v;

    cin >> n;
    for (int i = 0; i < n; i++){
        long long int num;
        long long int check2;
        long long int check3;
        long long int cnt2 = 0;
        long long int cnt3 = 0;

        cin >> num;

        check2 = num;
        check3 = num;

        while(1){
            if (check2 % 2 != 0){
                break;
            }
            
            check2 = check2 / 2;
            cnt2++;
        }

        while (1) {
			if (check3 % 3 != 0) {
				break;
			}
			check3 = check3 / 3;
			cnt3++;
		}

        v.push_back(pair<long long int, pair<long long int, long long int>>(cnt3, pair<long long int, long long int>(cnt2, num)));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++){
        cout << v[i].second.second << ' ';
    }
}