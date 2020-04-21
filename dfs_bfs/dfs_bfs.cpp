#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1010;
vector <int> graph[MAX];
bool visited[MAX], bfs_visited[MAX];

vector<int> merging(vector<int> left, vector<int> right){
  vector<int> result;
  int lsize = left.size();
  int rsize = right.size();
  int l=0;
  int r=0;
  while(l<lsize && r<rsize){
    if(left[l] < right[r]){
      result.push_back(left[l++]);
    }else{
      result.push_back(right[r++]);
    }
  }
  while(l<lsize){
    result.push_back(left[l++]);
  }
  while(r<rsize){
    result.push_back(right[r++]);
  }
  return result;
}

vector<int> mergeSort(vector<int> arr){
  int size = arr.size();
  if(size <= 1) return arr;
  int mid = size/2;

  vector<int> left(arr.begin(), arr.begin()+mid);
  vector<int> right(arr.begin()+mid, arr.end());

  return merging(mergeSort(left), mergeSort(right));
}

void dfs(int x){
  visited[x] = true;
  cout << x << " ";
  for(int i=0;i<graph[x].size();i++){
    int target = graph[x][i];
    if(!visited[target]){
      dfs(target);
    }
  }
}

void bfs(int x){
  queue<int> Queue;
  Queue.push(x);
  bfs_visited[x] = true;
  while(!Queue.empty()){
    int target = Queue.front();
    Queue.pop();
    cout << target << " ";

    for(int i=0;i<graph[target].size();i++){
      int next = graph[target][i];
      if(bfs_visited[next]) continue;
      bfs_visited[next] = true;
      Queue.push(next);
    }
  }
}

int main(){
  // vector<int> test;
  // test.push_back(3);
  // test.push_back(2);
  // test.push_back(5);
  // test.push_back(1);
  // test = mergeSort(test);
  // for(int i=0;i<test.size();i++){
  //   cout << test[i] << " ";
  // }
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(int i=0;i<n;i++){
    graph[i] = mergeSort(graph[i]);
  }
  dfs(0);
  cout << "\n";
  bfs(0);
  cout << "\n";
}