#include <iostream>
using namespace std;

int pascal[40][40] = { 1, };
int N, M;

int main() {
    cin >> N >> M;
    if (N == M) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            if (i == 0) {
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
            if (i < j) break;
        }
    }
    
    cout << pascal[N-2][M-1];

    return 0;
}