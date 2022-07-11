#include <iostream>
using namespace std;

int N;
int arr[10010];
int dp[10010];

int main(){
    cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i<N; i++){
        for (int j = 0; j<i; j++){
            dp[i] = max(dp[i], dp[i-j], arr[j])
        }
    }
}