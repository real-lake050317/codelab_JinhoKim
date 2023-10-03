#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int c[8];
vector<int> a[8];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    c[start] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            if (!c[y]) {
                q.push(y);
                c[y] = true;
            }
        }
    }
}

