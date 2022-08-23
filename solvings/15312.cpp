#include <iostream>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int num[30] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1, };
char alphabet[30] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', };

stack<int> dp;

stack<int> calc(stack<int> a) {
    if (a.size() == 3) {
        return a;
    }
    stack<int> st;
    while (true) {
        int k = a.top();
        a.pop();
        st.push((k + a.top())%10);
        if (a.size() == 1) {
            break;
        }
    }
    return calc(st);
}

int main() {
    char a[2010], b[2010];
    cin >> a >> b;

    for (int i = 0; i<strlen(a); i++) {
        int k = 0;
        for (int j = 0; j<30; j++) {
            if (a[i] == alphabet[j]) {
                k = j;
                break;
            }
        }
        dp.push(num[k]);
        for (int j = 0; j<30; j++) {
            if (b[i] == alphabet[j]) {
                k = j;
                break;
            }
        }
        dp.push(num[k]);
    }
    stack<int> st = calc(dp);

    while(st.size() > 1) { 
        int k = st.top();
        st.pop();
        cout << (k + st.top())%10;
    }

}