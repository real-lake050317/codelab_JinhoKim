#include <iostream>

int main() {
    int T, j;
    long long x, y, sub, n1, n2;
    std::cin >> T;
 
    for (int i = 0; i < T; i++) {
        std::cin >> x >> y;
        sub = y - x;
        n1 = 0; n2 = 0; j = 0;
        while (n1 < sub) {
            n2 += j * 2;
            n1 += ++j * 2;
        }
        printf("%d\n", n1 - sub < j ? j * 2 : j * 2 - 1);
    }
    return 0;
}
