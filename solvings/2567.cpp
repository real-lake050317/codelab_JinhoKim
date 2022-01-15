#include <iostream>
using namespace std;

int board[101][101] = {0, };	
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int T, x, y;
int cnt = 0;

int main(){
	cin >> T;
	for (int i = 0; i<T; i++){
		cin >> x >> y;
		for (int j = x; j<x+10; j++){
			for (int k = y; k<y+10; k++){
				board[j][k] = 1;
			}
		}
	}
	for (int i = 0; i<100; i++){
		for (int j = 0; j<100; j++){
			if (board[i][j] == 1){
				for (int k = 0; k<4; k++){
					int movex = dx[k];
					int movey = dy[k];
					if (board[i + movex][j + movey] == 0){
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt;
}
