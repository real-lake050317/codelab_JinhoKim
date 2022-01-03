#include <iostream>
#include <queue>
using namespace std;
int n;
long long sum;
priority_queue<int> pq;

int main() {
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a); a -= i; pq.push(a);
        if (!pq.empty() && pq.top() > a) {
            sum += pq.top() - a;
            pq.pop(); pq.push(a);
        }
    }
    printf("%lld", sum);
    return 0;
}
