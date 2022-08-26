#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans = 1, len1 = 1, len2 = 1;
int arr[100010];

int main() {
    cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i<N; i++) {
        if (arr[i] < arr[i+1]) {
            len1++;
        } else {
            len1 = 1;
        }
    }
}