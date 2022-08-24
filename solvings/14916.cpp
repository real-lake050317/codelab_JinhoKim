#include <iostream>
using namespace std;

int n;
int ans = 100000;

int main() {
    cin >> n;
    for (int i = 0; i<=n/5; i++) {
        int temp;
        if ((n - i*5)%2 == 0) {
            temp = i + (n - i*5)/2;
            if (temp < ans) ans = temp;
        }
    }
    if (ans == 100000) cout << -1;
    else cout << ans;
}