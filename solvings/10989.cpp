#include <iostream>
using namespace std;

int main(){
    int cnt[10010] = {0, };
    int n;
    cin>>n;
    for (int i = 0; i<n; i++){
        int x;
        cin>>x;
        cnt[x] += 1;
    }
    for (int i = 1; i<=10000; i++){
        for (int j = 1; j<=cnt[i]; j++){
            cout<<i<<"\n";
        }
    }
}