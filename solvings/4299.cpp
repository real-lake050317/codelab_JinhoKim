#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int ans = 1; 

int main(){
	cin >> N >> M;
	int board[N+1][M+1];
	
	for (int i = 0; i<N; i++){
		int a;
		cin >> a;
		for (int j = M-1; j>=0; j--){
			board[i][j] = a%10;
			a /= 10;
		}
	} //보드 완성
	
	for (int i = 0; i<N; i++){
		for (int j = 0; j<M; j++){
			for (int k = j; k<M; k++){
				if (board[i][j] == board[i][k]){
					if (board[i][j] == board[i-j+k][j] && board[i][j] == board[i-j+k][k]){
						ans = max(ans, (k-j+1)*(k-j+1));
					}
				}
			}
		}
	}
	cout << ans;
}
