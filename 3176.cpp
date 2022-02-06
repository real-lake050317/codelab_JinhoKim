#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <cstring>
using namespace std;

int node_num;
int min_result = 1000001, max_result = 0;
const int TREE_HIGHT = 20;
const int MAX_NUM = 100000;
int depth[MAX_NUM], parent[MAX_NUM+1][TREE_HIGHT];
int min_road[MAX_NUM+1][TREE_HIGHT], max_road[MAX_NUM+1][TREE_HIGHT];
vector<pair<int,int>> adj[MAX_NUM+1];

void FindParent(int par, int now, int dep, int road_len){
  depth[now] = dep;
  parent[now][0] = par;
  min_road[now][0] =  max_road[now][0] = road_len;
  for(int i = 0; i<adj[now].size(); ++i){
    if(adj[now][i].first != par) FindParent(now, adj[now][i].first, dep+1,adj[now][i].second);
  }
}

pair<int,int> FindMinMaxRoad(int a, int b){
  int min_result = 1000001, max_result = 0;

  if(depth[a] != depth[b]){
    if(depth[a] < depth[b]) swap(a,b);
    
    int dif = depth[a] - depth[b];
    
    for(int i=0; dif>0 ; ++i){
      if(dif %2 ==1){
        min_result = min(min_result, min_road[a][i]);
        max_result = max(max_result, max_road[a][i]);
        a = parent[a][i];
      }
      dif = dif>>1;
    }
  }

  if(a != b){
    for(int k = TREE_HIGHT-1; k>=0 ; --k){
      if(parent[a][k] != 0 && parent[a][k] != parent[b][k]){
        min_result = min(min_result, min_road[a][k]);
        min_result = min(min_result, min_road[b][k]);

        max_result = max(max_result, max_road[a][k]);
        max_result = max(max_result, max_road[b][k]);
        a = parent[a][k];
        b = parent[b][k];
      }
    }

    min_result = min(min_result, min_road[a][0]);
    min_result = min(min_result, min_road[b][0]);
    
    max_result = max(max_result, max_road[a][0]);
    max_result = max(max_result, max_road[b][0]);
  }
  
  return make_pair(min_result, max_result);
}

int main(){
  memset(parent, 0 , sizeof(parent));
  memset(min_road, 1000001, sizeof(min_road));
  memset(max_road, 0, sizeof(max_road));
  cin >> node_num;
  
  int a,b,road;
  for(int i = 0; i<node_num-1 ; ++i){
    cin >> a >> b >> road;
    adj[a].push_back(make_pair(b, road));
    adj[b].push_back(make_pair(a, road));
  }
  

  FindParent(0, 1, 0, 0);

  for(int k = 1; k<TREE_HIGHT ; ++k)
    for(int idx = 2 ; idx<=node_num ; ++idx)
      if(parent[idx][k-1] != 0){
        parent[idx][k] = parent[parent[idx][k-1]][k-1];
        min_road[idx][k] = min(min_road[parent[idx][k-1]][k-1], min_road[idx][k-1]);
        max_road[idx][k] = max(max_road[parent[idx][k-1]][k-1], max_road[idx][k-1]);
      }

  int pair_num;
  pair<int, int> result;
  cin >> pair_num;

  while(pair_num--){
    cin >> a >> b;
    result = FindMinMaxRoad(a,b);
    cout << result.first << result.second << endl;
  }

  return 0;
}
