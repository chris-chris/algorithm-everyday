#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 105;
vector<int> graph[MAX];
bool visited[MAX];

int bfs(int x){
  int cnt = 0;
  visited[x] = true;
  queue<int> Queue;
  Queue.push(x);
  while(!Queue.empty()){
    int target = Queue.front();
    Queue.pop();
    for(int i=0;i<graph[target].size();i++){
      int next = graph[target][i];
      if(visited[next]) continue;
      visited[next] = true;
      Queue.push(next);
      cnt++;
    }
  }
  return cnt;
}

int main() {

  int n, m;
  cin >> n;
  cin >> m;
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int cnt = bfs(1);
  cout << cnt << endl;

  return 0;
}