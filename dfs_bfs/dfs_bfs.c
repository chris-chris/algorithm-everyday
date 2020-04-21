#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX=1000;
int n,m;
vector <int> graph[MAX];
bool dfs_visited[MAX];
bool bfs_visited[MAX];

void mergeSort(vector<int> arr, int s, int e){
  if(e<=s) return;

  int m = (s+e)/2;
  // 5 2 4 3 6
  // s:0 e:4 m:2
  // 5 2 4 / 3 6
  mergeSort(arr, s, m);
  mergeSort(arr, m+1, e);

  int x=s; // s~m
  int y=m+1; // m+1~e
  int tmp[MAX];

  for(int i=s;i<=e;i++){
    if(x<=m && y<=e && arr[x]<=arr[y]) tmp[i]=arr[x++];
    if(x<=m && y<=e && arr[x]>arr[y]) tmp[i]=arr[y++];
    if(x>m && y<=e) tmp[i]=arr[y++];
    if(x<=m && y>e) tmp[i]=arr[x++];
  }
  for(int i=s;i<=e;i++){
    arr[i] = tmp[i];
  }

}

void DFS(int x){
  printf("%d ", x);
  dfs_visited[x] = true;
  sort(graph[x].begin(), graph[x].end());
  for(int i=0;i<graph[x].size();i++){
    // mergeSort(graph[x], 0, graph[x].size()-1);
    int y = graph[x][i];
    if(dfs_visited[y] == false){
      DFS(y);
    }
  }
}

void BFS(int x){
  queue <int> Queue;
  Queue.push(x);
  bfs_visited[x] = true;

  while(!Queue.empty()){
    int y = Queue.front();
    Queue.pop();

    printf("%d ", y);

    // mergeSort(graph[y], 0, graph[y].size()-1);
    sort(graph[y].begin(), graph[y].end());
    for(int i=0;i<graph[y].size();i++){
      int t = graph[y][i];
      if(bfs_visited[t] == false){

        bfs_visited[t] = true;
        Queue.push(t);
      }
    }
  }
}

int main() {

  scanf("%d %d", &n, &m);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(int i=0;i<n;i++){
    dfs_visited[i]=false;
    bfs_visited[i]=false;
  }
  DFS(0);
  printf("\n");
  BFS(0);
  return 0;
}