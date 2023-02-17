#include <iostream>
using namespace std;

int stringToLower(char *a) {
    int i = 0;
    while (a[i] != '\0') {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] = a[i] + 32;
        }
        i++;
    }
    return 0;
}

int main() {
    bool isSame = false;
    int max = 0;
    char a[1000000];
    int ans[30] = {0, };
    cin >> a;
    stringToLower(a);

    cout << a[1000] << endl;

    for (auto& i: a) {

    }


    for (int i = 0; i < 26; i++) {
        cout << ans[i] << " ";
    }

    if (isSame) {
        cout << "?" << endl;
    } else {
        for (int i = 0; i < 26; i++) {
            if (max == ans[i]) {
                cout << (char)(i + 'A') << endl;
                break;
            }
        }
    }

}