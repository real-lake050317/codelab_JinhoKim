#include <iostream>
#include <algorithm>
using namespace std;

int board[1010];
int n, k;
int cnt = 0;

int main(){
	cin >> n >> k;
	for (int i = 2; i<=n; i++){
		board[i] = i;
	}
	for (int i = 2; i<=n; i++){
		for (int j = 1; i*j<=n; j++){
			if (board[i*j] == -1){
				continue;
			}
			board[i*j] = -1;
			cnt++;
			if (cnt == k){
				cout << i*j;
				return 0;
			}
		}
	}
	return 0;
}
