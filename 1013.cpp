#include <iostream>
#include <vector>
#include <regex>
using namespace std;
int n;

vector<string> v;

void solve() {
    for (int i = 0; i < n; i++) {
        cout << (regex_match(v[i], regex("(100+1+|01)+"))?"YES":"NO") << "\n";
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    solve();
    
    return 0;
}
