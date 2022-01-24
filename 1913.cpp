#include <iostream>
#include <cmath>
using namespace std;

int N, num, ansx, ansy;
int board[1000][1000] = {0, };
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
	cin >> N >> num;
	int x = 0;
	int y = 0;
	int cnt = N*N;
	int flg = 0;
	for (int i = 0; i<N-1; i++){
		board[y][x] = cnt;
		cnt--;
		y++;
	}
	for (int i = 0; i<N-1; i++){
		board[y][x] = cnt;
		cnt--;
		x++;
	}
	for (int i = 0; i<N; i++){
		board[y][x] = cnt;
		cnt--;
		y--;
	}
	x = N-1;
	y = 0;
	while (cnt){
		int movex = dx[flg];
		int movey = dy[flg];
		if (board[y+movey][x+movex] != 0){
			flg++;
			flg %= 4;
		}
		else{
			x += movex;
			y += movey;
			board[y][x] = cnt;
			cnt--;
		}
	}
	
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			cout << board[i][j] << " ";
			if (board[i][j] == num) {
				ansx = i;
				ansy = j;
			}
		}
		cout << "\n";
	}
	cout << ansx + 1 << " " << ansy + 1;
}
