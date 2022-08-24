#include <iostream>
using namespace std;

int N;
int ans = 0;

int dp(int n) {
    if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        ans += 1;
        return 0;
    }
    if (n % 2 == 0) {
        ans += n*n/4;
        return dp(n/2) + dp(n/2);
    }
    else {
        ans += (n*n - 1) / 4;
        return dp(n/2) + dp(n/2 + 1);
    }
    
}

int main() {
    cin >> N;
    dp(N);
    cout << ans;
}