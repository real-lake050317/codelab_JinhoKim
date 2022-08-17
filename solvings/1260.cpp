#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int s[1001][1001];
int n, m, v;

bool check[1001];

void dfs (int x) {
	cout << x << ' ';
	check[x] = true;
	for (int i = 1; i <= n; i++) {
		if (s[x][i] == 1 && check[i] == false) {
			dfs(i);
		}
	}
}

void bfs (int k) {
	queue<int> q;
	check[k] = true;
	q.push(k);
	while (!q.empty()) {
		int x = q.front();
		cout << x << ' ';
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (s[x][i] == 1 && check[i] == false) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		s[a][b] = 1;
		s[b][a] = 1;
	}

	dfs(v);
	cout << '\n';
	memset(check, 0, 1001);
	bfs(v);

	return 0;
}
