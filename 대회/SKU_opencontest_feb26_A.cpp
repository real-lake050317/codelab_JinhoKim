#include <iostream>
using namespace std;

int N;
const int MAX = 1e9 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int arr[N + 10];
	for (int i = 0; i<N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i<N; i++){
		int ai = arr[i];
		int min = MAX;
		int ans = 1e6 + 10;
		for (int j = i + 1; j<N; j++){
			if (arr[j] != ai && arr[j] < min) {
				min = arr[j];
				ans = j;
			}
		}
		if (min == MAX) cout << "-1" << " ";
		else cout << ans + 1 << " ";
	}
}
