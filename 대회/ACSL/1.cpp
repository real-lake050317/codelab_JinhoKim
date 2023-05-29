#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string input, ans;
int a, b;
vector<string> words;
vector<pair<string, int> > goodWords;
set<string> bad;
set<char> punctuations;

bool leftStop[100010], rightStop[100010];
string leftCol[100010], rightCol[100010], middle[100010];
int dashused[100010];
int maxleft = 0, maxmiddle = 0, maxright = 0, tblsz;

void init_bad() {
	string word = "";
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == ' ') {
			bad.insert(word);
			word = "";
		}
		else {
			word += ans[i];
		}
	}
	if (word != "") {
		bad.insert(word);
	}
	punctuations.insert('.');
	punctuations.insert('?');
	punctuations.insert('!');
	punctuations.insert(',');
	punctuations.insert(';');
	punctuations.insert(':');
}

string to_lower(string temp) {
	string ans = "";
	for (int i = 0; i < temp.size(); i++) {
		ans += (char)tolower(temp[i]);
	}
	return ans;
}

void init_input() {
	string word = "";
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			words.push_back(word);
			word = "";
		}
		else {
			word += input[i];
		}
	}
	if (word != "") {
		words.push_back(word);
	}
	for (int i = 0; i< words.size(); i++) {
		string cur = words[i];
		if (punctuations.find(cur[cur.size() - 1]) != punctuations.end()) {
			rightStop[i] = true;
			if (i + 1 < words.size()) {
				leftStop[i + 1] = true;
			}
			words[i] = cur.substr(0, cur.size() - 1);
		}
		cur = words[i];
		if (bad.find(to_lower(cur)) != bad.end()) {
			if (i > 0) {
				rightStop[i - 1] = true;
			}
			if (i + 1 < words.size()) {
				leftStop[i + 1] = true;
			}
		}
		else {
			goodWords.push_back(make_pair(to_lower(cur), i));
		}
	}
	sort(goodWords.begin(), goodWords.end());
}

void make_table() {
	tblsz = goodWords.size();
	for (int idx = 0; idx < tblsz; idx++) {
		int x = goodWords[idx].second;
		string cur = words[x];
		middle[idx] = cur;
		maxmiddle = max(maxmiddle, (int)cur.size());
		string tmp = "";
		bool yes = false;
		for (int i = x + 1; i <= x + 3; i++) {
			if (i >= words.size()) {
				break;
			}
			if (rightStop[i - 1]) {
				break;
			}
			if (yes) {
				tmp += " ";
			}
			tmp += words[i];
			yes = true;
		}
		rightCol[idx] = tmp;
		maxright = max(maxright, (int)tmp.size());
		stack<string> st;
		for (int i = x - 1; i >= x - 3; i--) {
			if (i < 0) {
				break;
			}
			if (leftStop[i + 1]) {
				break;
			}
			st.push(words[i]);
		}
		tmp = "";
		yes = false;
		while (!st.empty()) {
			string add = st.top();
			st.pop();
			if (yes) {
				tmp += " ";
			}
			tmp += add;
			yes = true;
		}
		leftCol[idx] = tmp;
		maxleft = max(maxleft, (int)tmp.size());
	}
	for (int i = 0; i < tblsz; i++) {
		dashused[i] = maxleft + maxmiddle + maxright - (int)leftCol[i].size() - (int)middle[i].size() - (int)rightCol[i].size();
 	}
}

int main() {
	getline(cin, input);
	getline(cin, ans);
	cin >> a >> b;
	a--;
	b--;
	init_bad();
	init_input();
	make_table();
	int mine = 2e9;
	int idx = a;
	for (int i = a; i <= b; i++) {
		if (dashused[i] < mine) {
			mine = dashused[i];
			idx = i;
		}
	}
	for (int i = 0; i < maxleft - (int)leftCol[idx].size(); i++) {
		cout << "-";
	}
	cout << leftCol[idx] << " <" << middle[idx];
	for (int i = 0; i < maxmiddle - (int)middle[idx].size(); i++) {
		cout << "-";
	}
	cout << "> " << rightCol[idx];
	for (int i = 0; i < maxright - (int)rightCol[idx].size(); i++) {
		cout << "-";
	}
}
