#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const long long mod = 1e9+7;
int n, m, par[2020], a[2020], b[2020];
long long ans, pw[2020];
vector<pair<int,int> > v[2020];

int f(int cur){
    if(cur == par[cur]) return cur;
    return par[cur] = f(par[cur]);
}

void uni(int aa, int bb, int pl) {
    aa = f(aa), bb=f(bb);
    if (aa>bb) swap(aa,bb);
    if (aa == bb) return;
    if (aa == 1 && bb == n) ans = (ans + pw[pl]) % mod;
    else if (aa == 1) par[bb] = aa;
    else par[aa] = bb;
}

bool sol(int pq, int tk[], int road) {
	return !pq == tk[tk[pq]];
}

int main(){
    cin >> n >> m;
    for (int i = 0; i<m; i++) 
		cin >> a[i] >> b[i];
    for (int i = 0; i<m; i++) {
    	a[i]++; 
		b[i]++;
	}
    pw[0]=1;
    for (int i = 1; i<m; i++) 
		pw[i] = (pw[i - 1] * 3) % mod;
    for (int i = 1; i<=n; i++) 
		par[i] = i;

    for (int i = m - 1; i>=0; i--) 
		uni(a[i], b[i], i);

    cout << ans;
    return 0;
}
