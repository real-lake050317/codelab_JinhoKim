#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;

char board[50][50];
int dp[50][50];
bool visited[50][50];
int n, m;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int dfs(int y, int x){
	if (y<0 || x<0 || x >=m || y >= n|| board[y][x] == 'H') return 0;
	if (visited[y][x]){
		cout << "-1";
		return 0;
	}
	int &cache = dp[y][x];
	if (cache != -1) return cache;
	
	visited[y][x] = true;
	cache = 0;
	for (int dir = 0; dir<4; ++dir){
		int newy = y + dy[dir]*(board[y][x]-'0');
		int newx = x + dx[dir]*(board[y][x]-'0');
		
		cache = max(cache, dfs(newy, newx) + 1);
		
	}
	visited[y][x] = false;
	return cache;
}

int main(){
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 0 ; i<n; ++i){
		cin >> board[i];
	}
	cout <<dfs(0, 0);
	
	return 0;
}
