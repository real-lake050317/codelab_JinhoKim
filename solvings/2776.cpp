#include <iostream>
#include <map>
using namespace std;

map<int, bool> num;

int T;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;

	while (T--){
		int N, M, a;
		num.clear();
		cin >> N;
		for (int i = 0; i<N; i++){
			cin >> a;
			num.insert(pair<int, bool>(a, true));
		}
		cin >> M;
		for (int i = 0; i<M; i++){
			cin >> a;
			if (num[a] == true) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
	}
}