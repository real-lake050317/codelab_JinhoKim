#include <iostream>
using namespace std;

int N;
long long fib[100] = {1, 1, };

int main() {
    cin >> N;
    for (int i = 2; i<N; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    long long ans = fib[N-1]*2 + (fib[N-1] + fib[N-2])*2;
    cout << ans;
}