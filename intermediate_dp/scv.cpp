#include <iostream>
#include <map>
#include <utility>

using namespace std;

const int MAX = 1010;
int n,m;
int data[MAX][MAX];
map<pair<int,int>,int> cache;

int dp(int y, int x){
  if(y>=n) return 0;
  if(x>=m) return 0;

  pair<int,int> key = make_pair(y,x);
  if(cache.count(key))
    return cache[key];

  int result;
  int down = dp(y+1, x) + data[y][x];
  int right = dp(y, x+1) + data[y][x];
  if(down>right) result = down;
  else result = right;
  cache[key] = result;
  return result;
}

int main() {
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> data[i][j];
    }
  }
  int ret = dp(0, 0);
  cout << ret << endl;

  return 0;
}