#include <iostream>
using namespace std;

int T;
short n;
short dp[20] = { 0, 1, 2, 4, };

int main(){
    cin >> T;
    while (T--){
        cin >> n;
        for (int i = 4; i<12; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << "\n";
    }
}