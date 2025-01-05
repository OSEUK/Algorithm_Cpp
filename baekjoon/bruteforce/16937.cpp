/**
 * BAEKJOON ONLINE JUDGE
 * 문제명 : 두 스티커
 * 난이도 : SILVER III
 */

#include <iostream>
#include <vector>
#include <climits>


using namespace std;

int H, W, N;

int calc(const pair<int, int>& a, const pair<int, int>& b){
    int area = a.first * a.second + b.first * b.second;
    
    // 두 스티커를 붙일 수 없으면 0 반환
    // case1: 회전 없이 원래 모양
    if ((a.first <= H && b.first <= H && a.second + b.second <= W) ||
        (a.first <= W && b.first <= W && a.second + b.second <= H))
        return area;
        
    // case2: 첫 번째 스티커만 회전
    if ((a.second <= H && b.first <= H && a.first + b.second <= W) ||
        (a.second <= W && b.first <= W && a.first + b.second <= H))
        return area;
        
    // case3: 두 번째 스티커만 회전
    if ((a.first <= H && b.second <= H && a.second + b.first <= W) ||
        (a.first <= W && b.second <= W && a.second + b.first <= H))
        return area;
        
    // case4: 두 스티커 모두 회전
    if ((a.second <= H && b.second <= H && a.first + b.first <= W) ||
        (a.second <= W && b.second <= W && a.first + b.first <= H))
        return area;
    
    return 0;  // 어떤 방법으로도 붙일 수 없는 경우
}

int solution(const vector<pair<int, int>>& stickers){
    int result = 0;

    for (int i = 0; i < N - 1; i++){
        for (int j = i + 1; j < N; j++){
            result = max(result, calc(stickers[i], stickers[j]));
        }
    }

    return result;
}

int main(void){
    
    cin >> H >> W >> N;

    vector<pair<int, int>> stickers;

    for (int i = 0; i < N; i++){
        int R, C;
        cin >> R >> C;

        stickers.push_back({R, C});
    }

    cout << solution(stickers) << "\n";    
}