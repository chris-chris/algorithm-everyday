#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct node{
  int y;
  int x;
  int step;
};

vector<node> diffusors;
int n,m;
const int MAX = 200;
int data[MAX][MAX];
int result[MAX][MAX];
vector<node> diffs;
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool is_valid(int y, int x){
  if(y<0 || y>=n) return false;
  if(x<0 || x>=m) return false;
  return true;
}

int bfs(int diff_idx){
  int max_step = 0;
  queue<node> Queue;
  node node1 = diffs[diff_idx];

  Queue.push(node1);
  result[node1.y][node1.x] = 1;
  while(!Queue.empty()){
    node1 = Queue.front();
    int y = node1.y;
    int x = node1.x;

    bool spread = false;
    Queue.pop();
    for(int i=0;i<4;i++){
      int step = node1.step;
      int dy = dirs[i][0];
      int dx = dirs[i][1];
      int y2 = y + dy;
      int x2 = x + dx;
      if(!is_valid(y2, x2)) continue;
      if(result[y2][x2] > 0) continue;
      if(data[y2][x2] == 1) continue;
      node node2;
      node2.y = y2;
      node2.x = x2;
      if(data[y2][x2] == 2){
        step = step+1;
      }else{
        step = step+1;
        if(max_step < step) max_step = step;
      }
      node2.step = step;


      Queue.push(node2);
      result[y2][x2] = step;
      spread = true;
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(result[i][j] == 0 && data[i][j] == 0) return -1;
    }
  }

  return max_step;
}

int main() {

  cin >> n >> m;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> data[i][j];
      if(data[i][j]==2){
        node node1;
        node1.y = i;
        node1.x = j;
        node1.step = 0;
        diffs.push_back(node1);
      }
    }
  }
  int min_step = 999999999;
  for(int i=0;i<diffs.size();i++){

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        result[i][j] = 0;
      }
    }

    int step = bfs(i);
    // for(int i=0;i<n;i++){
    //   for(int j=0;j<m;j++){
    //     cout << result[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << i << ":" << step << endl;

    if(step != -1 && step < min_step){
      min_step = step;
    }
  }
  if(min_step == 999999999){
    cout << -1 << endl;
  }else{
    cout << min_step << endl;
  }


  return 0;
}