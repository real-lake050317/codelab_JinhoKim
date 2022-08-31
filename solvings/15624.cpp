#include <iostream>

int D[1000001] = { 0, 1 };

int main(){
    int n;
    std::cin >> n;
    for(int i = 2; i <= n; i++)
        D[i] = (D[i - 1] + D[i - 2]) % 1000000007;
    std::cout << D[n];
}
