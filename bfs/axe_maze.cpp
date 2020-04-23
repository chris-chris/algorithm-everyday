#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
  int x;
  int y;
  int axe;
};

int n, m;
const int MAX = 1010;
int data[MAX][MAX];
int check[MAX][MAX][2];
int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

bool isValid(int y, int x){
  if(y<0 || y>=n) return false;
  if(x<0 || x>=m) return false;
  return true;
}

int bfs(int y, int x){
  node item;
  item.x = x;
  item.y = y;
  item.axe = 1;

  queue<node> Queue;
  Queue.push(item);
  check[y][x][1] = 0;
  while(!Queue.empty()){
    item = Queue.front();

    int y = item.y;
    int x = item.x;
    int axe = item.axe;
    Queue.pop();
    for(int i=0;i<4;i++){
      int dy = dirs[i][0];
      int dx = dirs[i][1];
      int y2 = y + dy;
      int x2 = x + dx;
      if(!isValid(y2, x2)) continue;
      if(data[y2][x2] == 1 && axe == 1){

        node item2;
        item2.y = y2;
        item2.x = x2;
        item2.axe = 0;

        if(check[y2][x2][0] == 0){
          Queue.push(item2);
          check[y2][x2][0] = check[y][x][axe] + 1;
        }

      }
      if(data[y2][x2] == 1) continue;

      node item2;
      item2.y = y2;
      item2.x = x2;
      item2.axe = axe;

      if(check[y2][x2][axe] == 0){
        Queue.push(item2);
        check[y2][x2][axe] = check[y][x][axe] + 1;
      }

    }
  }
}

int main() {

  // (n-1, 0) => (0, m-1)

  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> data[i][j];
      check[i][j][0] = 0;
      check[i][j][1] = 0;
    }
  }
  bfs(n-1, 0);
  if(check[0][m-1][0] > check[0][m-1][1] && check[0][m-1][1] != 0){
    cout << check[0][m-1][1] << endl;
  }else{
    cout << check[0][m-1][0] << endl;
  }

  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++){
  //     cout << check[i][j][0] << " ";
  //   }
  //   cout << endl;
  // }
  return 0;
}