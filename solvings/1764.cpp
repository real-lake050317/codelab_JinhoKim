#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, M, cnt = 0;

map<string, bool> person;
string ans[500010];

int main(){
    string a;
    cin >> N >> M;
    person.clear();

    for (int i = 0; i<N; i++){
        cin >> a;
        person.insert(make_pair(a, true));
    }

    for (int i = 0; i<M; i++){
        cin >> a;
        if (person[a] == true){
            ans[cnt] = a;
            cnt++;
        }
    }

    cout << cnt << "\n";
    sort(ans, ans + cnt);

    for (int i = 0; i < cnt; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}