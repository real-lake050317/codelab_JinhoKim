#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<ll> *Q[300010];
int N, M, V, P[300010], C[300010], D[300010];
ll E[300010];

int main(){
	cin >> N >> M;
	V = N + M;
	for (int i = 2; i<=V; i++) cin >> P[i] >> C[i];
	for (int i = 1; i<=V; i++) Q[i] = new priority_queue<ll>;
	for (int i = V; i>=2; i--){
		ll p = 0, q = 0;
		if (D[i]){
			for (int j=1;j<D[i];j++){
				E[i] += (*Q[i]).top();
				(*Q[i]).pop();
			}
			p = (*Q[i]).top();
			(*Q[i]).pop();
			
			q = (*Q[i]).top();
			(*Q[i]).pop();
		}
		
		(*Q[i]).push(p+C[i]);
		(*Q[i]).push(q+C[i]);
		E[i] -= C[i];

		priority_queue<ll> *&a = Q[i], *&b = Q[P[i]];
		
		if (a->size() > b->size()) swap(a,b);
		while (!a->empty()){
			(*b).push((*a).top());
			(*a).pop();
		}
		
		E[P[i]] += E[i];
		D[P[i]]++;
	}
	ll ans = E[1];
	for (int i=0;i<D[1];i++){
		ans += (*Q[1]).top();
		(*Q[1]).pop();
	}
	cout << ans << endl;

	return 0;
}
