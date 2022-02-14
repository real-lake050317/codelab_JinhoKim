#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;
const int N = 1e5+5, inf = 1e9, mod = 1e9+7;

struct BIT{
    int n; ll*tree;
    BIT(int k){
        n = k;
        tree = new ll[n+1];
        clear();
    }
    void clear(){for(int i=0;i<=n;i++) tree[i]=0;}
    ~BIT(){delete[] tree;}
    void upd(int p,ll v){
        for(;p<=n;p+=p&-p) tree[p]+=v;
    }
    ll qry(int p){
        ll res = 0;
        for(;p>0;p-=p&-p)
            res += tree[p];
        return res;
    }
};
struct Seg{
    int st; ll*tree,sum;
    Seg(int k){
        st = 1<<int(ceil(log2(k)));
        tree = new ll[2*st];
        clear();
    }
    ~Seg(){delete[] tree;
    void clear(){int i=0; i<=2*st; i++) tree[i]=0;}
    void upd(int p,ll v){
        for(tree[p+=st]+=v;p>1;p>>=1)
            tree[p>>1] = tree[p] + tree[p^1];
    }
    int lb(ll K,ll&val){
        int id = 1;
        if(tree[id]<K) return -1;
        val = 0;
        while(id<st){
            ll Lval = tree[id<<1];
            if(Lval>=K) id=(id<<1);
            else id=(id<<1|1), K-=Lval, val+=Lval;
        }
        return id-st;
    }
};

struct Liquid{
    int d,p,l;
}A[N];

void solve(){
    int n,Q,M=0;
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        int d,p,l; cin>>d>>p>>l;
        A[i] = {d,p,l};
        M = max(M,d+1);
    }
    sort(A+1,A+n+1,[](auto&a,auto&b){
        return a.p<b.p;
    });
    vector<int> L[M];
    for(int i=1;i<=n;i++)
        L[A[i].d].pb(i);
    Seg f(n+1); BIT f2(n+1);
    vector<pair<ll,ll>> qry(Q);
    for(int i=0;i<Q;i++)
        cin>>qry[i].first>>qry[i].second;
    vector<int> lo(Q,0),hi(Q,M);
    while(true){
        int todo = 0,done = 0;
        vector<vector<int>> G; G.resize(M+1);
        for(int i=0;i<Q;i++){
            if(lo[i]+1<hi[i]){
                ++todo;
                G[lo[i]+hi[i]>>1].push_back(i);
            }
        }
        if(!todo) break;
        f.clear(); f2.clear();
        for(int i=M-1;i>=1;i--){
            for(int j:L[i]){
                f.upd(j,A[j].l);
                f2.upd(j,1LL*A[j].p*A[j].l);
            }
            for(int j:G[i]){
                ll g,l; tie(g,l) = qry[j];
                ll val;
                int id = f.lb(l,val);
                if(id==-1){hi[j]=i; continue;}
                ll cost = f2.qry(id-1) + (l-val)*A[id].p;
                if(cost <= g) lo[j] = i;
                else hi[j] = i;
            }
            done += G[i].size();
            if(todo == done) break;
        }
    }
    for(int ans:lo){
        cout << (ans?ans:-1) << "\n";
	}
};

int main(){
	solve();
}
