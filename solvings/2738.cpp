#include <iostream>
using namespace std;

int main() {
    int a[110][110], b[110][110], ans[110][110];
    int N, M;
    cin >> N >> M;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}