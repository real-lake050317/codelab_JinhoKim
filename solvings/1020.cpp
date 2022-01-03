#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
 
string s;
int c[10] = { 6,2,5,5,4,5,6,3,7,5 };
vector<long long> dp[2][15];
long long inputTime = 0;
long long max_c = 0;
 
void recurrence(int);

int main(void) {
    cin >> s;
 
    int line = 0;
 
    for (int i = 0; i < s.size(); i++) {
        line += c[s[i] - '0'];
        inputTime *= 10;
        inputTime += (s[i] - '0');
    }
 
    max_c = (long long)pow(10, s.size());
   
    for (int i = 0; i < 15; i++) {
        dp[0][i] = vector<long long>(106, max_c * 2);
        dp[1][i] = vector<long long>(106, max_c * 2);
    }
 
    for (long long i = 0; i < 10; i++) {
        dp[0][0][c[i]] = min(dp[0][0][c[i]], i);
 
        if (s[s.size() - 1] - '0' < i)
            dp[1][0][c[i]] = min(dp[1][0][c[i]], i);
    }
 
    recurrence(1);
 
    cout << min(max_c + dp[0][s.size() - 1][line], dp[1][s.size() - 1][line]) - inputTime << endl;
 
    return 0;
}
 
void recurrence(int index) {
    if (index == s.size()) return;
 
    for (int i = index * 2; i <= index * 7; i++) {
        long long nextTime;
        for (int j = 0; j < 10; j++) {
            nextTime = dp[0][index - 1][i] + (long long)pow(10, index) * j;
            dp[0][index][i + c[j]] = min(dp[0][index][i + c[j]], nextTime);
 
            if (s[s.size() - 1 - index] - '0' < j)
                dp[1][index][i + c[j]] = min(dp[1][index][i + c[j]], nextTime);
        }
 
        for (int j = s[s.size() - 1 - index] - '0'; j < 10; j++) {
            nextTime = dp[1][index - 1][i] + (long long)pow(10, index) * j;
            dp[1][index][i + c[j]] = min(dp[1][index][i + c[j]], nextTime);
        }
    }
 
    recurrence(index + 1);
}
