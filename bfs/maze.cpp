#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
using namespace std;

const int MAX = 1010;
int n, m;
int data[MAX][MAX];
int dist[MAX][MAX];
bool check[MAX][MAX];
int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool isValid(int y, int x) {
  if(y<0 || y >= n) return false;
  if(x<0 || x >= m) return false;
  if(check[y][x]) return false;
  if(data[y][x] == 1) return false;
  return true;
}

int main() {

  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> data[i][j];
    }
  }

  pair<int, int> key = make_pair(n-1, 0);
  queue<pair<int,int>> Queue;
  Queue.push(key);
  check[n-1][0] = true;

  while(!Queue.empty()){
    key = Queue.front();
    int y = key.first;
    int x = key.second;
    Queue.pop();
    for(int i=0;i<4;i++){
      int dy = dirs[i][0];
      int dx = dirs[i][1];

      int y2 = y + dy;
      int x2 = x + dx;
      pair<int,int> key2 = make_pair(y2, x2);
      if(isValid(y2,x2)){
        Queue.push(key2);
        check[y2][x2] = true;
        dist[y2][x2] = dist[y][x] + 1;
      }

    }
  }

  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++){
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << dist[0][m-1] << endl;


  return 0;
}