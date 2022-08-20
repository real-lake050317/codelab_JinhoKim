#include <iostream>
using namespace std;

int rec = 0, dyn = 0;

int recursive(int n) {
    if (n == 1 || n == 2) {
        rec++;
        return 1;
    }
    else {
        return (recursive(n-1) + recursive(n-2));
    }
}

int dynamic (int n) {
    int dp[n+1];
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dyn++;
    }
    return dp[n];

}

int main() {
    int n;
    cin >> n;
    recursive(n);
    dynamic(n);
    cout << rec << " " << dyn;
    return 0;
}