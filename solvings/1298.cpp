#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> Fail(string pattern) {
	int m = pattern.length();
	vector<int> pi(m);
	pi[0] = 0;
	for (int i = 1, j = 0; i < m; i++) { 
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1]; 
		if (pattern[i] == pattern[j])
			pi[i] = ++j; 
	} 
	return pi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int L;
	cin >> L;
	string ad;
	cin >> ad;
	vector<int> pi = Fail(ad);
	cout << L - pi[L - 1];
	
	return 0;
}
