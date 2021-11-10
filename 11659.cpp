#include <iostream>
using namespace std;

int main(){
	int m, n;
	cin >> n >> m;
	int arr[n+10];
	int sum[n+10] = {0, };
	for (int i = 0; i<n; i++){
		cin >> arr[i];
		if (i == 0) sum[i] = arr[i];
		else sum[i] = sum[i-1] + arr[i];
	}
	for (int k = 0; k < m; k++){
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i-1] << "\n";
	}
	
	return 0;
}
