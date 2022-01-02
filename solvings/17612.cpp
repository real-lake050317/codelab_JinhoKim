#include <iostream>
#include <queue>
using namespace std;

struct compare {
  bool operator()(pair<int, int>&a, pair<int, int>&b) {
    if (a.first == b.first) {
      return a.second < b.second;
    } 
    else{
      return a.first > b.first;
    }
  }
};

int main(){
 
  priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > min_pq;
  priority_queue<pair<int,int>,vector<pair<int,int>>, compare > result_pq;

  int customer_num,counter_num;
  cin >> customer_num >> counter_num;

  vector<queue<pair<int,int>>> lines;
  lines = vector<queue<pair<int,int>>>(counter_num);

  int customer_idx, item_num ;
  bool pass = false;
  for(int i=0; i<counter_num ; ++i ){

    if(i >= customer_num ){
      pass = true;
      break;
    }
      
    cin >> customer_idx >> item_num;
    lines[i].push(make_pair(item_num, customer_idx));
    min_pq.push(make_pair(item_num, i));
  }

  int line_idx, waiting_time;
  if(!pass)
  for(int i=counter_num ; i<customer_num ; ++i){
    cin >> customer_idx >> item_num;

    line_idx = min_pq.top().second;
    waiting_time = min_pq.top().first + item_num;

    lines[line_idx].push(make_pair(waiting_time, customer_idx));
    min_pq.pop();
    min_pq.push(make_pair(waiting_time, line_idx));
  }

  long long result =0;
  for(int i=0; i<counter_num ; ++i ){
    if(i >= customer_num )
      break;
    result_pq.push(make_pair(lines[i].front().first, i));
  }

  for(int i=1; i<=customer_num ; ++i){

    line_idx = result_pq.top().second; 

    customer_idx = lines[line_idx].front().second;
    result = result + ( (long long)i*(long long)customer_idx);
    result_pq.pop(); 
    lines[line_idx].pop();

    if(!lines[line_idx].empty())
      result_pq.push(make_pair(lines[line_idx].front().first,line_idx));
  }

  cout << result << endl;
  return 0;
}