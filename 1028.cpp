#include <iostream>
#include <algorithm>
using namespace std;
char map[770][770];
int R, C;
int D1[770][770];
int D2[770][770];
int D3[770][770];
int D4[770][770];

bool isOutOfBounds(int r, int c) {
	return r < 0 || r >= R || c < 0 || c >= C;
}

int main(void) {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> map[i];
	for (int d = 0; d <= R + C - 2; d++) {
		for (int c = 0; c < C; c++) {
			int r = d - c;
			if (isOutOfBounds(r, c))
				continue;
			if (isOutOfBounds(r + 1, c - 1))
				D3[r][c] = (map[r][c] == '1');
			else
				D3[r][c] = (map[r][c] == '1') * (D3[r + 1][c - 1] + 1);
		}
		for (int r = 0; r < R; r++) {
			int c = d - r;
			if (isOutOfBounds(r, c))
				continue;
			if (isOutOfBounds(r - 1, c + 1))
				D1[r][c] = (map[r][c] == '1');
			else
				D1[r][c] = (map[r][c] == '1') * (D1[r - 1][c + 1] + 1);
		}
	}
	for (int d = 1-C; d <= R-1; d++) {
		for (int r = 0; r < R; r++) {
			int c = r - d;
			if (isOutOfBounds(r, c))
				continue;
			if (isOutOfBounds(r - 1, c - 1))
				D4[r][c] = (map[r][c] == '1');
			else
				D4[r][c] = (map[r][c] == '1') * (D4[r - 1][c - 1] + 1);
		}
		for (int r = R-1; r >= 0 ; r--) {
			int c = r - d;
			if (isOutOfBounds(r, c))
				continue;
			if (isOutOfBounds(r + 1, c + 1))
				D2[r][c] = (map[r][c] == '1');
			else
				D2[r][c] = (map[r][c] == '1') * (D2[r + 1][c + 1] + 1);
		}
	}
	int mx = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			int mx_side = min(D1[r][c], D2[r][c]);
			if (mx_side < mx)
				continue;
			for (int sz = mx_side; sz >= 1; sz--) {
				if (c + 2 * (sz - 1) >= C)
					continue;
				if (sz < mx)
					break;
				if (min(D3[r][c + 2 * (sz - 1)], D4[r][c + 2 * (sz - 1)]) >= sz) {
					mx = max(mx, sz);
					break;
				}
			}
		}
	}
	cout << mx;
}
