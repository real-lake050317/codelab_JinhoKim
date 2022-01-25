#include <bits/stdc++.h>
using namespace std;

int n, b, s, r;

vector<pair<long long, long long> > g[5050], rg[5050];
long long d[5050], rd[5050];

long long dp[5050][5050], opt[5050][5050];
long long val[5050], sum[5050];

void dijkstra(int st, vector<pair<long long, long long> > g[5050], long long dst[5050]){
	priority_queue<pair<long long, long long> > pq; pq.push({ 0, st }); dst[st] = 0;
	while (pq.size()){
		long long now = pq.top().second;
		long long cst = -pq.top().first;
		pq.pop();
		if (cst > dst[now]) continue;
		for (auto i : g[now]){
			long long nxt = i.first;
			long long nxtCst = i.second + cst;
			if (nxtCst < dst[nxt]){
				dst[nxt] = nxtCst;
				pq.push({ -nxtCst, nxt });
			}
		}
	}
}

long long cst(int a, int b){
	return (sum[b] - sum[a]) * (b - a - 1);
}

void go(int t, int s, int e, int l, int r){
	if (s > e) return;
	int m = s + e >> 1;
	dp[t][m] = opt[t][m] = -1;
	for (int k = l; k <= min(m - 1, r); k++){
		long long now = dp[t - 1][k] + cst(k, m);
		if (dp[t][m] == -1 || dp[t][m] > now){
			dp[t][m] = now; opt[t][m] = k;
		}
	}
	go(t, s, m - 1, l, opt[t][m]);
	go(t, m + 1, e, opt[t][m], r);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> b >> s >> r;
	for (int i = 0; i < r; i++){
		int s, e, x; cin >> s >> e >> x;
		g[s].push_back({ e, x });
		rg[e].push_back({ s, x });
	}
	memset(d, 0x3f, sizeof d);
	memset(rd, 0x3f, sizeof rd);
	dijkstra(b + 1, g, d);
	dijkstra(b + 1, rg, rd);
	for (int i = 1; i <= b; i++){
		val[i] = d[i] + rd[i];
	}
	sort(val + 1, val + b + 1);
	for (int i = 1; i <= b; i++){
		sum[i] = sum[i - 1] + val[i];
	}
	for (int i = 1; i <= b; i++){
		dp[1][i] = sum[i] * (i - 1);
		opt[1][i] = 1;
	}
	for (int i = 2; i <= s; i++){
		go(i, i, b, 0, b);
	}
	cout << dp[s][b];
}
