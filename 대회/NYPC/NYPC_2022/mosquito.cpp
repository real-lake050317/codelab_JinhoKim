#include <iostream>
using namespace std;

int board[50][50];
int N, M;
int ans = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int digx[4] = {1, -1, 1, -1};
int digy[4] = {1, -1, -1, 1};


int main() {
    cin >> N >> M;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i<N; i++) {
        for (int j = 0; j< N; j++) {
            int temp = board[i][j];
            int temp_diag = board[i][j];

            for (int k = 0; k<4; k++) {
                for (int l = 1; l<=M; l++) {
                    int nx = i + dx[k] * l;
                    int ny = j + dy[k] * l;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                        break;
                    }
                    temp += board[nx][ny];
                }
                for (int l = 1; l<=M; l++) {
                    int nx = i + digx[k] * l;
                    int ny = j + digy[k] * l;
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                        break;
                    }
                    temp_diag += board[nx][ny];
                }
            }


            if (temp > ans) {
                ans = temp;
            }
            if (temp_diag > ans) {
                ans = temp_diag;
            }
        }
    }
    cout << ans << endl;
}