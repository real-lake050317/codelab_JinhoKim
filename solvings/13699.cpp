#include <iostream>
using namespace std;

int n;
long long dp[100] = { 1, };

int main() {
    cin >> n;
    for (int i = 1; i<n; i++) {
        long long temp;
        for (int j = 0; j < i; j++) {
            temp += dp[n-j-1] * dp[j];
        }
        dp[i] = temp;
    }
    cout << dp[n];
}