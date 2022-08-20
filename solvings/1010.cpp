#include <iostream>
using namespace std;

int T;

int main() {
    cin >> T;
    for (int i = 0; i<T; i++) {
        int N, M;
        long long mcn = 1;

        cin >> N >> M;

        int cnt = 1;

        for (int i = M; i > M-N; i--) {
            mcn *= i;
            mcn /= cnt++;
        }
        cout << mcn << endl;
    }

    return 0;
}