#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
vector<int> arr;
vector<int> tree;

void build_tree(int node, int s, int e){
    if (s == e){
        tree[node] = arr[s];
        return;
    }
    
    int mid = (s + e) / 2;
    build_tree(2 * node, s, mid);
    build_tree(2 * node + 1, mid + 1, e);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void update(int node, int i, int v, int s, int e){
    if (s == e){
        tree[node] = v;
        return;
    }

    int mid = (s + e) / 2;
    if (i <= mid){
        update(node * 2, i, v, s, mid);
    } else {
        update(node * 2 + 1, i, v, mid + 1, e);
    }

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int find(int node, int s, int e, int i, int j){
    if (i > e || j < s){
        return INT_MAX;
    } 

    if (i <= s && e <= j){
        return tree[node];
    }

    int mid = (s + e) / 2;
    
    return min(find(node * 2 , s, mid, i, j), find(node * 2 + 1, mid + 1, e, i, j));
}


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    arr.resize(N);
    tree.resize(4 * N + 1);

    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    build_tree(1, 0, N - 1);

    cin >> M;
    while (M--){
        int order, i, j;
        cin >> order >> i >> j;

        switch(order){
            case 1 :
                update(1, i - 1, j, 0, N-1); 
                break;
            case 2 :
                cout << find(1, 0, N-1, i - 1, j - 1) << "\n";
                break;
        }
    }
}