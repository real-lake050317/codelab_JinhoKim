#include <x86intrin.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;

template<size_t _Nw> void _M_do_sub(_Base_bitset<_Nw>& A, const _Base_bitset<_Nw>& B) {
	for (int i = 0, c = 0; i < _Nw; i++) c = _subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*) & A._M_w[i]);
}

template<> void _M_do_sub(_Base_bitset<1>& A, const _Base_bitset<1>& B) { A._M_w -= B._M_w; }
template<size_t _Nb> bitset<_Nb>& operator-=(bitset<_Nb>& A, const bitset<_Nb>& B) { return _M_do_sub(A, B), A; }
template<size_t _Nb> inline bitset<_Nb> operator-(const bitset<_Nb>& A, const bitset<_Nb>& B) { bitset<_Nb> C(A); return C -= B; }

template<size_t sz = 50000>

int LCS(string& a, string& b) {
    bitset<sz> D, x, S[26];
    for (int i = 0; i < b.size(); i++) S[b[i] - 'A'][i] = 1;
    for (int i = 0; i < a.size(); i++) {
        x = S[a[i] - 'A'] | D; D <<= 1, D[0] = 1;
        D = x && (x ^ (x - D));
    }
    return D.count();
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b; 
    cin >> a >> b;
    cout << LCS(a, b) << endl;
}
