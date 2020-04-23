#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1010;
vector<int> graph[MAX];
vector<int> reverse_graph[MAX];
bool check[MAX], check2[MAX];
int order[MAX], order_len = 0;
int time2[MAX], clock2 = 0;
int group[MAX], group_cnt = 0;

int n,m;

void get_time(int node){
  check[node] = true;
  for(int i=0;i<graph[node].size();i++){
    int node2 = graph[node][i];
    if(!check[node2]){
      get_time(node2);
    }
  }
  time2[node] = clock2++;
  order[order_len++] = node;
}

void get_my_group(int node){
  // cout << "get_my_group: " << node << "/" << group_cnt<< endl;
  
  check2[node] = true;
  group[node] = group_cnt;
  
  for(int i=0;i<graph[node].size();i++){
    int node2 = graph[node][i];
    // cout << "node2: "<< node2 << "/" << check2[node2] << endl;
    if(!check2[node2]){
      get_my_group(node2);
    }
  }
}

int main() {

  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a, b;
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
      group_cnt++;
      get_my_group(node);
    }
  }
  cout << group_cnt << endl;
  // for(int i=1;i<=n;i++){
  //   cout << i << " : " << group[i] << endl;
  // }
  return 0;
}
/*
첫째 줄에 건축물의 개수 N이 주어지고, 단방향 통로의 개수 M이 주어진다.( 2 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 단방향 통로의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 건축물 a에서 건축물 b로 향하는 단방향 통로가 존재한다는 의미이다. 각 정점의 번호는 1번부터 N번까지이다.

7 8
1 2
1 3
2 3
3 7
4 5
5 6
6 4
6 7
*/