#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0); 
	int m, n, a;
	cin >> n >> m;
	int sum[n+10];
	sum[0] = 0;
	for (int i = 1; i<=n; i++){
		cin >> a;
		sum[i] = sum[i-1] + a;
	}
	
	for (int k = 0; k < m; k++){
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i-1] << "\n";
	}
	
	return 0;
}
