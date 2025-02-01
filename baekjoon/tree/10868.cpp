#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define INF (1e9 + 1)

int N, M;
vector<int> arr;
vector<int> tree;

void build(int node, int s, int e){
    if (s == e){
        tree[node] = arr[s];
        return;
    }

    int mid = (s + e) / 2;
    build(2 * node + 1, s, mid);
    build(2 * node + 2, mid + 1, e);

    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

int find(int node, int s, int e, int l, int r){
    if (l > e || r < s){
        return INF;
    }

    if (l <= s && e <= r){
        return tree[node];
    }
    
    int mid = (s + e) / 2;
    return min(find(2 * node + 1, s, mid, l, r), find(2 * node + 2, mid + 1, e, l, r));
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    arr.resize(N);
    tree.resize(4 * N);
    
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    build(0, 0, N-1);

    while (M--){
        int a, b;
        cin >> a >> b;
        
        cout << find(0, 0, N-1, a - 1, b - 1) << "\n";
    }
    
}