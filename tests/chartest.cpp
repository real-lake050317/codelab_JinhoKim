#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char a[100], b[100];
    cin >> a >> b;
    for (int i = 0; i<strlen(a); i++) {
        cout << a[i];
    }
    for (int i = 0; i<strlen(b); i++) {
        cout << b[i];
    }
}