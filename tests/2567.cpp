#include <iostream>
using namespace std;

int board[110][110] = {0, };
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int cnt = 0;
int N, x, y;

int main(void){
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> x >> y;
		for (int j = x; j<x+10; j++){
			for (int k = y; k<y+10; k++){
				board[k][j] = 1;
			}
		}
	}
	for (int i = 0; i<100; i++){
		for (int j = 0; j<100; j++){
			if (board[i][j] == 1){
				for (int k = 0; k<4; k++){
					if (!board[i+dx[k]][j+dy[k]]){
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt;
}


