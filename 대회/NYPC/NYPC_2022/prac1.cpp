#include <iostream>
#include <vector>
using namespace std;

int N, M;

struct User {
    int time;
    int s;
};

vector<vector<User>> v;
bool ans = true;

int main() {
    cin >> N >> M;
    v.resize(N + 1);
    
    for (int i = 0; i<M; i++) {
        int t, n, s;
        cin >> t >> n >> s;
        
        v[n].push_back({ t, s });
    }
    
    for (int i = 1; i <= N; i++) {
		int last_s = -1;
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j].s != j % 2) {
				ans = false;
				break;
			}
			if (v[i][j].s == 1) {
				if (v[i][j].time - v[i][j - 1].time < 60) {
					ans = false;
					break;
				}
			}
			last_s = v[i][j].s;
		}

		if (!ans) {
			break;
		}

		if (last_s == 0) {
			ans = false;
			break;
		}
	}
	
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
    
}
