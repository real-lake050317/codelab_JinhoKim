#include <iostream>
using namespace std;

int board[101][101] = {0, };
int movex[4] = {1, 0, -1, 0};
int movey[4] = {0, 1, 0, -1};
int T;
int ans = 0;

int main(){
	cin >> T;
	int x, y;
	for (int i = 0; i<T; i++){
		cin >> x >> y;
		for (int j = x; j<x+10; j++){
			for (int k = y; k<y+10; k++){
				board[j][k] = 1;
			}
		}
	}
	for (int i = 1; i<101; i++){
		for (int j = 1; j<101; j++){
			if (board[i][j] == 1){
				for (int k = 0; k<4; k++){
					int nx = x + movex[k];
					int ny = y + movey[k];
					if (board[ny][nx] == 0) ans++;
				}
			}
		}
	}
	cout << ans;
}
