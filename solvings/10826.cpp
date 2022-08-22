#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> sumStack(stack<int> a, stack<int> b) {
    stack<int> dp;

    bool flag = 0;

    while (!a.empty() && !b.empty()) {
        int aint = a.top();
        int bint = b.top();
        if (aint + bint + flag >= 10) {
            dp.push((aint + bint + flag)%10);
            flag = 1;
        } else {
            dp.push((aint + bint + flag)%10);
            flag = 0;
        }
        a.pop();
        b.pop();
    }

    while (!a.empty()) {
        int aint = a.top();
        if (aint + flag >= 10) {
            dp.push((aint + flag)%10);
            flag = 1;
        }
        else {
            dp.push((aint + flag)%10);
            flag = 0;
        }
        a.pop();
    }

    while (!b.empty()) {
        int bint = b.top();
        if (bint + flag >= 10) {
            dp.push((bint + flag) % 10);
            flag = 1;
        }
        else {
            dp.push((bint + flag)%10);
            flag = 0;
        }
        b.pop();
    }

    if (flag) {
        dp.push(1);
    }

    while (!dp.empty()) {
        int a = dp.top();
        cout << a;
        dp.pop();
    }

    return dp;
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        int a = s.top();
        cout << a;
        s.pop();
    }
}

int main() {
    int N;
    cin >> N;
    vector<stack<int> > vec;
    stack<int> a;
    stack<int> b;
    a.push(0);
    b.push(1);
    vec.push_back(a);
    vec.push_back(b);
    for (int i = 2; i<N; i++){
        stack<int> c = sumStack(vec[i-1], vec[i-2]);
        printStack(sumStack(vec[i-1], vec[i-2]));
        vec.push_back(c);
    }
}