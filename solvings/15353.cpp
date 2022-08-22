#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    char a[10010], b[10010];

    stack<int> anum;
    stack<int> bnum;
    stack<int> dp;

    bool flag = 0;
    
    cin >> a >> b;
    
    for (int i = 0; i<strlen(a); i++) {
        int aint = (int)a[i] - 48;
        anum.push(aint);
    }

    for (int i = 0; i<strlen(b); i++) {
        int bint = int(b[i]) - 48;
        bnum.push(bint);
    }
    
    while (!anum.empty() && !bnum.empty()) {
        int aint = anum.top();
        int bint = bnum.top();
        if (aint + bint + flag >= 10) {
            dp.push((aint + bint + flag)%10);
            flag = 1;
        } else {
            dp.push((aint + bint + flag)%10);
            flag = 0;
        }
        anum.pop();
        bnum.pop();
    }

    while (!anum.empty()) {
        int aint = anum.top();
        if (aint + flag >= 10) {
            dp.push((aint + flag)%10);
            flag = 1;
        }
        else {
            dp.push((aint + flag)%10);
            flag = 0;
        }
        anum.pop();
    }

    while (!bnum.empty()) {
        int bint = bnum.top();
        if (bint + flag >= 10) {
            dp.push((bint + flag) % 10);
            flag = 1;
        }
        else {
            dp.push((bint + flag)%10);
            flag = 0;
        }
        bnum.pop();
    }

    if (flag) {
        dp.push(1);
    }

    while (!dp.empty()) {
        int a = dp.top();
        cout << a;
        dp.pop();
    }
    return 0;
}