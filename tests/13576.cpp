#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <memory.h>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
using namespace std;

char st[100002];
ll jin[2][100001], wprhq[2][100001];
vector<int> vec;
int arr[100001];

int main() {
	int n, m, l, r, mid, ans;
	ll x = 1, y = 1, sum = 0;
	scanf("%s", st + 1);
	n = strlen(st + 1);
	for (int i = 0; i < n; i++) {
		wprhq[0][i] = x;
		wprhq[1][i] = y;
		x = x * 127 % mod1;
		y = y * 127 % mod2;
	}
	for (int i = 1; i <= n; i++) {
		jin[0][i] = (jin[0][i - 1] + st[i] * wprhq[0][n - i]) % mod1;
		jin[1][i] = (jin[1][i - 1] + st[i] * wprhq[1][n - i]) % mod2;
	}
	for (int i = 1; i <= n; i++) {
		ll tmp1 = (jin[0][n] - jin[0][n - i] + mod1) % mod1 * wprhq[0][n - i] % mod1;
		ll tmp2 = (jin[1][n] - jin[1][n - i] + mod2) % mod2 * wprhq[1][n - i] % mod2;
		if (tmp1*mod2 + tmp2 == jin[0][i] * mod2 + jin[1][i]) vec.push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		l = 0, r = vec.size() - 1;
		ans = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (vec[mid] > i) {
				r = mid - 1;
				continue;
			}
			ll tmp1 = (jin[0][i] - jin[0][i - vec[mid]] + mod1) % mod1 * wprhq[0][i - vec[mid]] % mod1;
			ll tmp2 = (jin[1][i] - jin[1][i - vec[mid]] + mod2) % mod2 * wprhq[1][i - vec[mid]] % mod2;
			if (tmp1*mod2 + tmp2 == jin[0][vec[mid]] * mod2 + jin[1][vec[mid]]) {
				ans = vec[mid];
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ans != 0) {
			sum++;
			arr[ans]++;
		}
	}
    cout << vec.size();
	for (int i : vec) {
        cout << i << " " << sum << "\n";
		sum -= arr[i];
	}
	return 0;
}
