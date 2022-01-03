#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int n, m, k;
pair<long long, long long> a[202020];
vector<pair<long long, long long> > v[404040];
long long ans;

int main(){
    ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);
    cin >> n >> m; 
	k = n + m;
    for(int i=1; i<=n; i++) cin >> a[i].x, a[i].y = 0;
    for(int i=1; i<=m; i++) cin >> a[i+n].x, a[i+n].y = 1;
    sort(a+1, a+k+1);

    int now = k;
    
    for(int i=1; i<=k; i++){
        if(a[i].y == 0) v[now++].push_back(a[i]);
        else v[--now].push_back(a[i]);
    }
    
    for(int i=0; i<404040; i++) if(v[i].size()) {
        ll t = 0;
        for(int j=1; j<v[i].size(); j+=2) t += abs(v[i][j].x - v[i][j-1].x);
        if(~v[i].size() & 1){ ans += t; continue; }
        ll mn = t;
        for(int j=v[i].size()-1; j-2>=0; j-=2){
            t += abs(v[i][j].x - v[i][j-1].x) - abs(v[i][j-1].x - v[i][j-2].x);
            mn = min(mn, t);
        }
        ans += mn;
    }
    
    cout << ans;
    
    return 0;
}
