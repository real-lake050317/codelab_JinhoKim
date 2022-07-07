#include <iostream>
#include <map>
using namespace std;

map<int, bool> num;
int N, M;


int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a;
    cin >> N;
    num.clear();

    for (int i = 0; i<N; i++){
        cin >> a;
        num.insert(make_pair(a, true));
    }

    cin >> M;
    
    for (int i = 0; i<M; i++){
        cin >> a;
        if (num[a] == true) cout << "1\n";
        else cout << "0\n";
    }
}