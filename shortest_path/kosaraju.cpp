#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100;
vector <int> List[MAX];
vector <int> reverseList[MAX];
int n,m;

int time2[MAX], clock2 = 1;
int order[MAX], order_len = 0;
int group[MAX], group_cnt = 1; // group[i]
bool check[MAX], check2[MAX];

void get_time(int node){
  
  check[node] = true;
  
  for(int i=0;i<List[node].size();i++){
    int node2 = List[node][i];
    if(!check[node2]){
      get_time(node2);
    }
  }
  
  time2[node] = clock2;
  clock2++;
  order[order_len++] = node;
}

void get_my_group(int node){
  // DFS
  
  check2[node] = true;
  group[node] = group_cnt;
  
  for(int i=0;i<reverseList[node].size();i++){
    int node2 = reverseList[node][i];
    
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
    
    List[a].push_back(b);
    reverseList[b].push_back(a);
    
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
  
  cout << group_cnt-1 << endl;
  
  // for(int i=1;i<=n;i++){
  //   cout << i << " : " << group[i] << endl;
  // }

  return 0;
}
/*
12 18
1 2
2 3 
2 4 
3 1 
3 7 
3 9 
4 6 
4 11 
5 4 
6 5 
7 8 
7 9 
8 10 
8 12 
9 10 
10 7 
11 12 
12 11
*/