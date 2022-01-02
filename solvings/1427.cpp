#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int i, int j){
	return j < i;
}

int main(){
	int n, arr[10];
	int cnt = 0;
	cin >> n;
	while (n != 0){
		arr[cnt] = n%10;
		n /= 10;
		cnt++;
	}
	sort(arr, arr + cnt, cmp);
	for (int i = 0; i<cnt; i++){
		cout << arr[i];
	}
}
