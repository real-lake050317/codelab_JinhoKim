#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;

void solve(int a[], int b[], int p, int q){
	for (int k = 0; k<M; k++){
		bool flg = 0;
		for (int l = 0; l<N; l++){
			if (b[k] == a[l]) {
				flg = 1;
				break;
			}
		}
		cout << flg << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	int t, n, m;
	cin >> T;
	for (int i = 0; i<T; i++){
		cin >> N;
		int arrn[N+10];
		for (int j = 0; j<N; j++){
			cin >> arrn[j];
		}
		sort(arrn, arrn + n);
		cin >> M;
		int arrm[M+10];
		for (int j = 0; j<M; j++){
			cin >> arrm[j];
		}
		sort(arrm, arrm + m);
		solve(arrn, arrm, N, M);
	}
} 
