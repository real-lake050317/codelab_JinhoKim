#include <iostream>
using namespace std;

int main(){
	int n, m, a, index, init, final;
	cin >> n >> m;
	int arr[n][m];
	int sum[n*n];
	sum[0] = 0;
	for (int i = 0; i<n; i++){
		for (int j = 1; j<=n; j++){
			cin >> a;
			index = i*4+j;
			sum[index] = sum[index-1] + a;
			//cout<<sum[index]<<"\n";
		}
	}
	for (int i = 0; i<m; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		init = (y1-1)*4 + x1;
		final = (y2-1)*4 + x2;
		cout << sum[final] - sum[init-1] << "\n";
	}
	
}
