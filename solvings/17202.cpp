#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

queue<int> v;
string s1, s2;


void solve(queue<int> v) {
    if (v.size() == 2) {
        cout << v.front() << "" << v.back() << endl;

        return;
    }
    queue<int> v2;
    while (v.size() > 1) {
        int x = v.front();
        v.pop();
        int y = v.front();
        v2.push((x+y)%10);
    }
    solve(v2);
}

int main() {
    cin >> s1 >> s2;
    for (int i = 0; i<8; i++) {
        v.push(s1[i] - '0');
        v.push(s2[i] - '0');
    }
    solve(v);
}