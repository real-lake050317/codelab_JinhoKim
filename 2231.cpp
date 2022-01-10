#include <iostream>
using namespace std;

int main(){
    int n, sum;
    int ans = 0;
    cin >> n;
    for (int i = 0; i<n; i++){
        sum = i;
        int num = i;
        for (int j = 0; j<7; j++){
            sum += num%10;
            num /= 10;
        }
        sum += num;
        if (sum == n){
            ans = i;
            break;
        }
    }
    if (ans){
        cout << ans;
    }
    else{
        cout << "0";
    }
    
    return 0;
}
