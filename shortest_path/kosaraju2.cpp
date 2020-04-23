#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1010;
vector<int> graph[MAX], reverse_graph[MAX];
int n, m;
int time2[MAX], clock2 = 1;
int order[MAX], order_len = 0;
int group[MAX], group_cnt = 1;
bool check[MAX], check2[MAX];

void get_time(int node){
  check[node] = true;
  for(int i=0;i<graph[node].size();i++){
    int node2 = graph[node][i];
    if(!check[node2]){
      get_time(node2);
    }
  }

  time2[node] = clock2;
  clock2++;
  order[order_len++] = node;

}

void get_my_group(int node){
  check2[node] = true;
  group[node] = group_cnt;
  for(int i=0;i<reverse_graph[node].size();i++){
    int node2 = reverse_graph[node][i];
    if(!check2[node2]){
      get_my_group(node2);
    }
  }
}

int main() {

  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;

    graph[a].push_back(b);
    reverse_graph[b].push_back(a);

  }

  for(int i=1;i<=n;i++){
    if(!check[i]){
      get_time(i);
    }
  }
  for(int i=order_len-1;i>=0;i--){
    int node = order[i];
    if(!check2[node]){
      get_my_group(node);
      group_cnt++;
    }
  }
  cout << group_cnt - 1 << endl;


  return 0;
}