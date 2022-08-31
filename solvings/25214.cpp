#include <iostream>
using namespace std;

int N, arr[200010], maxVal = 0, minVal = 1000000001;

int main() {
    cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
        cout << maxVal - minVal << endl;
    }
}