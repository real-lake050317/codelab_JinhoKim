#include <iostream>
using namespace std;

int main(){
    int N;
    long long fact = 1;
    cin >> N;
    for (long long i = N; i >= 1; i--){
        fact *= i;
        while (fact % 10 == 0){
            fact /= 10;
        }
        fact %= 1000000000000;
    }
    fact %= 100000;
    if (fact % 100000 == fact % 10000){
        if (fact % 10000 == fact % 1000){
            if (fact % 1000 == fact % 100){
                if (fact % 100 == fact % 10){
                    cout << "0000" << fact << "\n";
                }
                else cout << "000" << fact << "\n";
            }
            else cout << "00" << fact << "n";
        }
        else cout << "0" << fact << "\n";
    }
    else cout << fact << "\n";
}
