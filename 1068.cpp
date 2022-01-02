#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int N;
	cin >> N;
    vector<int> v[N];
 
    for(int i = 0; i < N; i++)
        v[i].push_back(1);
 
    for(int i=0; i < N; i++){
        int num;
		cin >> num;
        if(num == -1)
            continue;
        else
            v[num].push_back(i);
    }
 
    int del; 
	cin >> del;
    int leaf = 0;
    
    queue<int> q;
    q.push(del);
    v[del][0] = 0;
 
    while(!q.empty()){
        int x=q.front();
        v[x][0] = 0;
        q.pop();
        for(int i = 1; i < v[x].size(); i++){
            q.push(v[x][i]);
            v[x][i] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = v[i].size()-1; j >= 1; j--){
            if(v[i][j] == del){ 
                v[i].erase(v[i].begin() + j);
                i = N;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        if(v[i][0] && v[i].size() == 1){
            leaf++;
    	}
	}
	cout << leaf;
	
	return 0;
}
