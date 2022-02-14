#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr)
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fi first
#define se second
#define cat(a, b) a##b
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll S = 100 + 10, MOD = 998244353;
 
struct st {
    int i;
    bool operator()(int r, int c) {
        return (i & (1 << (r * 5 + c)));
    }
    void print() {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++)
                cout << (tmp(i, j) ? '#' : '.'); //((i & (1 << (i * 5 + j))) ? "#" : ".");
            cout << '\n';
        }
        cout << '\n';
    }
    bool row(int r) {
        for (int i = 0; i < 5; i++) 
            if (!tmp(r, i)) return false;
        return true;
    }
    bool col(int c) {
        for (int i = 0; i < 5; i++)
            if (!tmp(i, c)) return false;
        return true;
    }
    bool dia1() { 
        // ¢Ù
        for (int i = 0; i < 5; i++)
            if (!tmp(i, i)) return false;
        return true;
    }
    bool dia2() {
        // ¢×
        for (int i = 0; i < 5; i++)
            if (!tmp(i, 4 - i)) return false;
        return true;
    }
    bool is_bingo(int r, int c) {
        if (r == c and dia1()) return true;
        if (r == 4 - c and dia2()) return true;
        return row(r) or col(c);
    }
    int count(function<bool(int, int)> f) {
        int ret = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++)
                ret += f(i, j);
        }
        return ret;
    }
    bool tmp(int r, int c) {
        return (i & (1 << (r * 5 + c)));
    }
} now;
function<bool()> f[5][5];
 
int main() {
    fast;
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    f[0][0] = []() { 
        return !now.dia2();
    };
    f[0][1] = []() {
        return !(now.row(0) or now.col(1));
    };
    f[0][2] = []() {
        return now.dia1();
    };
    f[0][3] = []() {
        return now(3, 3);
    };
    f[0][4] = []() {
        return now.is_bingo(0, 4);
    };
    f[1][0] = []() {
        return !now(3, 0);
    };
    f[1][1] = []() {
        if (!now.dia1() and !now.dia2()) return false;
        bool chk1 = false, chk2 = false;
        for (int i = 0; i < 5; i++) {
            chk1 = chk1 or now.row(i);
            chk2 = chk2 or now.col(i);
        }
        return chk1 and chk2;
    };
    f[1][2] = []() {
        return now(1, 2);
    };
    f[1][3] = []() {
        return now.count([&](int r, int c) {return now(r, c); }) <= 17;
    };
    f[1][4] = []() {
        return now.count([&](int r, int c) {return now.is_bingo(r, c); }) % 2 == 0;
    };
    f[2][0] = []() {
        return now.is_bingo(2, 0);
    };
    f[2][1] = []() {
        return now.count([&](int r, int c) {return now(r, c) and !now.is_bingo(r, c); }) >= 5;
    };
    f[2][2] = []() {
        return !now(2, 2) or now.is_bingo(2, 2);
    };
    f[2][3] = []() {
        int cnt = 0;
        for (int i = 0; i < 5; i++)
            cnt += now.col(i);
        return cnt >= 2;
    };
    f[2][4] = []() {
        return now.count([&](int r, int c) {return !now.is_bingo(r, c); }) >= 10;
    };
    f[3][0] = []() {
        return !now(1, 0);
    };
    f[3][1] = []() {
        return now.row(1) or now.col(3);
    };
    f[3][2] = []() {
        int cnt = 0;
        for (int i = 0; i < 5; i++)
            cnt += now(i, 2);
        return cnt <= 3;
    };
    f[3][3] = []() {
        return now(0, 3);
    };
    f[3][4] = []() {
        return now.dia1() or now.dia2();
    };
    f[4][0] = []() {
        return now(4, 4);
    };
    f[4][1] = []() {
        return ??;
    };
    f[4][2] = []() {
        return now(4, 2);
    };
    f[4][3] = []() {
        int cnt = (int)now.dia1() + (int)now.dia2();
        for (int i = 0; i < 5; i++)
            cnt += (int)now.row(i) + (int)now.col(i);
        return cnt >= 3;
    };
    f[4][4] = []() {
        return now(4, 0);
    };
 
    for (now.i = 0; now.i < (1 << 25); now.i++) {
        bool valid = true;
        if (now.i % 200000 == 0) cout << now.i << '\n';
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (now(i, j) != f[i][j]()) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            cout << now.i << '\n';
            now.print();
        }
    }
}
