#include <iostream>
using namespace std;

int N, M;

struct data {
    int a;
    int b;
    int c;
};

struct data arr[1001];
bool ans = false;

int main() {
    cin >> N >> M;
    if (M%2 == 1) {
        ans = true;
    }
    
    for (int i = 0; i<M; i++) {
        int t, k, s;
        cin >> t >> k >> s;
        arr[i].a = t;
        arr[i].b = k;
        arr[i].c = s;
    }
    
    for (int i = 0; i<M; i++) {
        bool flag = false;
        for (int j = i + 1; j<M; j++) {
            if (arr[i].b == arr[j].b && i != j) {
                if (arr[i].c == arr[j].c) {
                    flag = true;
                    break;
                } else {
                    if (arr[i].c > arr[j].c) {
                        cout << "HERE";
                        break;
                    }
                    else {
                        if (arr[i].a + 60 > arr[j].a) {
                            flag = true;
                            break;
                        }
                    }
                }
            } 
        }
        if (flag == true) {
            ans = true;
            break;
        }
    }
    
    if (ans) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}