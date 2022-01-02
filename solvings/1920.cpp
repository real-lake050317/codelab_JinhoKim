#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;
long long arr[100010];

void binarySearch(int key){
    long long start = 0;
    long long end = n-1;
    long long mid;
    while(end >= start){
        mid = (start+end)/2;
        if (arr[mid] == key){
            cout << "1" << endl;
            return;
        } else if(arr[mid] > key){
            end = mid -1;
        } else{
            start = mid + 1;
        }
    }
    cout << "0" << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cin >> m;
    sort(arr, arr + m);
    for (int i = 0; i<m; i++){
        int num;
        cin >> num;
        binarySearch(num);
    }
}
