#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct node {
  int y;
  int x;
  int step;
};

const int MAX = 105;
int n, m, k, t;
int data[MAX][MAX];
int dcnt = 0, t_idx = 0;
vector<node> ds;
vector<node> selected;
map<int, int> cnt;
int ds_idx[MAX];


void recursion(int idx, int didx){
  if(idx >= k){
    t_idx++;
    if(t_idx == t){
      for(int i=0;i<k;i++){
        int j = ds_idx[i];
        selected.push_back(ds[j]);
        // cout << ds[j].y << "," << ds[j].x << ":" << ds[j].step << endl;
      }
      // cout << endl;
    }
    return;
  }
  for(int i=didx;i<dcnt;i++){
    if(cnt[i] == 0){
      ds_idx[idx] = i;
      cnt[i] = 1;
      recursion(idx+1, i+1);
      cnt[i] = 0;
    }
  }
}

int main() {

  cin >> n >> m >> k >> t;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> data[i][j];
      if(data[i][j]==2) {
        dcnt++;
        node node1;
        node1.y = i;
        node1.x = j;
        node1.step = 0;
        ds.push_back(node1);
      }
    }
  }

  recursion(0, 0);

  for(int i=0;i<selected.size();i++){
    cout << selected[i].y << " " << selected[i].x << endl;
  }

  return 0;
}