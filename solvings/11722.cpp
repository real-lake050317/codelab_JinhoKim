#include <iostream>
using namespace std;

int A, ans = -1;
int num[1010];
int dp[1010];

int main(){
    cin >> A;

    for (int i = 0; i<A; i++) cin >> num[i];

    dp[0] = 1;

    for (int i = 0; i<A; i++) {
        dp[i] = 1;
        for (int j = 0; j<i; j++){
            if (num[i] < num [j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}