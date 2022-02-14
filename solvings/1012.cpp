#include <iostream>
#include <cstring>
using namespace std;

int T;
int M, N, K;
int board[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void boardset(){
	for (int i = 0; i<50; i++){
		memset(arr[i], 0, sizeof(arr[i]));
	}
}

int main(){
	cin >> T;
	while (T--){
		boardset();
		cin >> M >> N >> K;
		while (K--){
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		for (int i = 0; i<M; i++){
			for (int j = 0; j<N; j++){
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}
}
