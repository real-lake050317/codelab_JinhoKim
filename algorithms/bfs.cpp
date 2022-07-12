#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void bfs(int start){
    queue<int> q;
    q.push(start);
    c[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
    }
}

int main(){

}