#include <iostream>
using namespace std;

long long dp[120] = {1, 1, 1, };
int n;

int main() {
    cin >> n;
    for (int i = 3; i<n; i++) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    cout << dp[n - 1] << endl;

    return 0;
}