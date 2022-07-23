#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#define ll long long
using namespace std;

namespace miller_rabin {
	long long mul(long long x, long long y, long long mod) { return (__int128)x * y % mod; }
	long long _pow(long long x, long long y, long long p) {
		long long ret = 1, piv = x % p;
		while (y) {
			if (y & 1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(long long x, long long a) {
		if (x % a == 0) return 0;
		long long d = x - 1;
		while (1) {
			long long tmp = _pow(a, d, x);
			if (d & 1) return (tmp != 1 && tmp != x - 1);
			else if (tmp == x - 1) return 0;
			d >>= 1;
		}
	}
	bool isprime(long long x) {
		for (auto& i : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
			if (x == i) return 1;
			if (x > 40 && miller_rabin(x, i)) return 0;
		}
		if (x <= 40) return 0;
		return 1;
	}
}
namespace pollard_rho {
	void rec(long long n, vector<long long>& v) {
		if (n == 1) return;
		if (n % 2 == 0) {
			v.push_back(2);
			rec(n / 2, v);
			return;
		}
		if (miller_rabin::isprime(n)) {
			v.push_back(n);
			return;
		}
		ll a, b, c, g = n;
        auto f = [&](ll x) {
            return (c + miller_rabin::mul(x, x, n)) % n;
        };
        do {
            if (g == n) {
                a = b = rand() % (n - 2) + 2;
                c = rand() % 20 + 1;
            }
            a = f(a);
            b = f(f(b));
            g = gcd(abs(a - b), n);
        } while (g == 1);
		rec(g, v);
		rec(n / g, v);
	}
	vector<ll> factorize(ll n) {
		vector<long long> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n, cnt = 0;
	cin >> n;
	vector<long long> v = pollard_rho::factorize(n);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int bit = 1; bit < (1 << v.size()); bit++) {
		long long temp = 1;
		for (int i = 0; i < v.size(); i++) if (bit & (1 << i)) temp *= v[i];
		cnt += (__builtin_popcount(bit) & 1 ? 1 : -1) * n / temp;
	}
	cout << n - cnt << '\n';
}
