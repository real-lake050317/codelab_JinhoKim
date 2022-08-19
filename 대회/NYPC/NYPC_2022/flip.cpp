#include <iostream>
#include <cstdlib>
using namespace std;

int T;


int main() {
    cin >> T;
    int *num = (int*)malloc(sizeof(int) * T);
    for (int i = 0; i<T; i++) {
        cin >> num[i];
    }
    
}