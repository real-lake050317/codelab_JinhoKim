#include <iostream>
using namespace std;

int n;
int arr[50] = {0, 1, };

int main(){
	cin >> n;
	for (int i = 2; i<=n; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	cout << arr[n];
}
