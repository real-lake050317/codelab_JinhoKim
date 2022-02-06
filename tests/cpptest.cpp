#include <iostream>
using namespace std;

//write a dfs function
void dfs(int n, int* a, int* b, int* c) {
    if (n == 0) {
        cout << a[0] << " " << b[0] << " " << c[0] << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        dfs(n - 1, a, b, c);
        if (n % 2 == 0) {
            swap(a[i], a[n - 1]);
            swap(b[i], b[n - 1]);
            swap(c[i], c[n - 1]);
        }
        else {
            swap(a[0], a[n - 1]);
            swap(b[0], b[n - 1]);
            swap(c[0], c[n - 1]);
        }
    }
}

int main(){

}