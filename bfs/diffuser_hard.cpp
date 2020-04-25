#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct node{
  int y;
  int x;
  int step;
};

const int MAX = 200;
int result[MAX][MAX];
int data[MAX][MAX];
vector<node> diffs;
vector<vector<node>> diffs_comb;
map<int, int> cnt;
int n, m, k;
int selected[MAX];
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool is_valid(int y, int x){
  if(y < 0 || y >= n) return false;
  if(x < 0 || x >= m) return false;
  return true;
}

void recursion(int idx, int diff_idx){
  if(idx >= k){
    // cout << "recursion finished" << endl;
    vector<node> item;
    // cout << "recursion: ";
    for(int i=0;i<k;i++){
      // cout << selected[i] << ",";
      item.push_back(diffs[selected[i]]);
    }
    // cout << endl;
    diffs_comb.push_back(item);
    return;
  }
  for(int i=diff_idx;i<=diffs.size();i++){
    if(cnt[i] == 0){
      cnt[i] = 1;
      selected[idx] = i;
      recursion(idx+1, i+1);
      cnt[i] = 0;
    }
  }
}

int bfs(int diff_idx){
  int max_step = 0;
  vector<node> item = diffs_comb[diff_idx];
  queue<node> Queue;
  for(int i=0;i<item.size();i++){
    // cout << "push" << item[i].y << "," << item[i].x << endl;
    Queue.push(item[i]);
    result[item[i].y][item[i].x] = 1;
  }
  while(!Queue.empty()){
    node node1 = Queue.front();
    int x = node1.x;
    int y = node1.y;
    Queue.pop();
    for(int i=0;i<4;i++){
      int dy = dirs[i][0];
      int dx = dirs[i][1];
      int y2 = y + dy;
      int x2 = x + dx;
      int step = node1.step;

      if(!is_valid(y2, x2)) continue;
      if(data[y2][x2] == 1) continue;

      if(result[y2][x2] > 0) continue;
      if(data[y2][x2] == 0){
        step++;
        max_step = step;
      }else if(data[y2][x2] == 2){
        step++;
      }
      // if(result[y2][x2] > 0 && result[y2][x2] > step){
      //   result[y2][x2] = step;
      // }else

      node node2;
      node2.x = x2;
      node2.y = y2;
      node2.step = step;
      result[y2][x2] = step;
      Queue.push(node2);

    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(data[i][j] == 0 && result[i][j] == 0) return -1;
    }
  }

  return max_step;
}

void task(int t){
  cin >> n >> m >> k;
  diffs.clear();
  diffs_comb.clear();

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> data[i][j];
      if(data[i][j] == 2){
        node node1;
        node1.y = i;
        node1.x = j;
        node1.step = 0;
        diffs.push_back(node1);
      }
      result[i][j] = 0;
    }
  }
  recursion(0,0);
  int min_step = 999999999;
  for(int i=0;i<diffs_comb.size();i++){
    int step = bfs(i);
    // cout << "bfs"<< i << ":" << step << endl;
    if(step != -1 && step < min_step){
      min_step = step;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        // cout << result[i][j] << " ";
        result[i][j] = 0;
      }
      // cout << endl;
    }
    // vector<node> item = diffs_comb[i];
    // for(int j=0;j<item.size();j++){
    //   cout << item[j].y << "," << item[j].x << endl;
    // }
    // cout << endl;
  }
  if(min_step == 999999999){
    cout << "#" << t << " -1" << endl;
  }else{
    cout << "#" << t << " " << min_step << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for(int i=1;i<=t;i++){
    task(i);
  }


  return 0;
}