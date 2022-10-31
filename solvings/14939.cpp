#include <iostream>
#include <algorithm>
using namespace std;

bool arr[15][15], tmp_arr[15][15];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
const int INF = 1e9, MAX = 10;
int ans = INF;

bool outrange(int x, int y) {
	if (x < 0 || x >= MAX || y < 0 || y >= MAX) return 1;
	return 0;
}

void toggle(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!outrange(nx, ny)) tmp_arr[nx][ny] = !tmp_arr[nx][ny];
	}
	tmp_arr[x][y] = !tmp_arr[x][y];
}

bool islight() {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (tmp_arr[i][j]) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			char c;
            cin >> c;
			if (c == 'O') arr[i][j] = 1;
		}
	}
	for (int step = 0; step < (1 << MAX); step++) {
		int cnt = 0;
		for (int i = 0; i < MAX; i++)
		    for (int j = 0; j < MAX; j++)
			    tmp_arr[i][j] = arr[i][j];

		for (int bit = 0; bit < MAX; bit++) {
			if (step & (1 << bit)) {
				cnt++;
				toggle(0, bit);
			}
		}
		for (int x = 1; x < MAX; x++) {
			for (int y = 0; y < MAX; y++){
				if (tmp_arr[x - 1][y]) {
					toggle(x, y);
					cnt++;
				}
			}
		}
		if (!islight()) ans = min(cnt, ans);
	}
	if (ans == INF) cout << "-1";
	else cout << ans;
}