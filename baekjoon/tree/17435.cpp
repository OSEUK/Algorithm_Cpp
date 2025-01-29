#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_LOG 20

using namespace std;

int m, Q;
vector<int> arr;
vector<vector<int>> par;

void build(){
    for (int k = 1; k < MAX_LOG; k++){
        for (int i = 1; i <= m; i++){
            int ancestor = par[k-1][i];
            
            if (ancestor == 0) continue;

            par[k][i] = par[k-1][ancestor];
        }
    }
}

int find(int n, int x){
    for (int k = MAX_LOG - 1 ; k >= 0; k--){
        if (n & (1 << k)) x = par[k][x];
    }

    return x;

}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m;
    arr.resize(m + 1);
    par.resize(MAX_LOG, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++){
        cin >> arr[i];
    }

    for (int i = 1; i <= m; i++){
        par[0][i] = arr[i];
    }

    build();

    cin >> Q;
    while (Q--){
        int n, x;
        cin >> n >> x;

        cout << find(n, x) << "\n";
    }
}
