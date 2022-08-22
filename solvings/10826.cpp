#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;


void printStack(stack<int> a) {
    while (!a.empty()) {
        cout << a.top();
        a.pop();
    }
    cout << "\n";
} 

stack<int> sum(stack<int> anum, stack<int> bnum) {
    stack<int> dp;

    bool flag = 0;
    
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
    return dp;
}


int main() {
    stack<int> anum;
    stack<int> bnum;
    vector<stack<int> > fib;
    int n;
    cin >> n;
    anum.push(0);
    bnum.push(1);
    fib.push_back(anum);
    fib.push_back(bnum);
    for (int i = 2; i<=n; i++) {
        fib.push_back(sum(fib[i-1], fib[i-2]));
    }
    printStack(fib[6]);
    printStack(fib[7]);
    printStack(sum(fib[6], fib[7]));
    //printStack(sum(testa, testb));

    /*
    stack<int> ans = fib[n-1];
    printStack(ans);
    */
}