// swea D2 새로운 불면증 치료법
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++){
        int N;
        cin >> N;

        int mask = 0;
        int i = 0;
        while ((mask + 1) != (1 << 10)){
            i++;
            int curr = N * i;
            while (curr){
                mask = mask | (1 << (curr % 10));
                curr /= 10;
            }
        }

        cout << "#" << t << " " << N * i << "\n";
    }
}