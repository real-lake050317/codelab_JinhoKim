#include <iostream>
#include <queue>
using namespace std;

int n, i, a, ans[1000001];
priority_queue<int> pq;

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a); a -= i;
        pq.push(a); pq.push(a); pq.pop();
        ans[i] = pq.top();
    } --i;
    while (--i) if (ans[i] > ans[i + 1]) ans[i] = ans[i + 1];
    for (i = 1; i <= n; i++) printf("%d\n", ans[i] + i);
    return 0;
}
