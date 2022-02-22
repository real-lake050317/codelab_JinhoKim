#include <bits/stdc++.h>
using namespace std;

int arr[8080], sum[8080];
int dp[880][8080], p[880][8080];

inline int cost(int i, int j){ 
	return (sum[j] - sum[i-1]) * (j-i+1); 
}

void go(int t, int l, int r, int pl, int pr){
	if(l > r) return;
	int mid = (l + r) >> 1;
	dp[t][mid] = -1;
	p[t][mid] = -1;
	for(int k = pl; k<=pr; k++){
		int tmp = dp[t-1][k] + cost(k+1, mid);
		if(dp[t][mid] == -1 || dp[t][mid] > tmp){
			dp[t][mid] = tmp;
			p[t][mid] = k;
		}
	}
	go(t, l, mid-1, pl, p[t][mid]);
	go(t, mid+1, r, p[t][mid], pr);
}

int main(){
	int m, n;
	cin >> m >> n;
	for(int i = 1; i<=m; i++){
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}
	for(int i = 0; i<=m; i++) dp[1][i] = cost(1, i), p[1][i] = 0;
	for(int t = 2; t<=n; t++) go(t, 0, m, 0, m);

	cout << dp[n][m];
}
