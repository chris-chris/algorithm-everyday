#include <iostream>

using namespace std;

const int MAX = 1010;
int data[MAX][MAX];
int cache[MAX][MAX];
int n, m, q;

int dp(int y, int x){
  // cout << "dp("<<y<<","<<x<<")"<<endl;
  if(y<0 || x<0) return 0;

  if(cache[y][x] != -999){
    return cache[y][x];
  }

  // a,b, c,d => (c,d) - (c,b-1) - (a-1,d) + (a-1,b-1)
  int result = 0;
  if(y-1>=0){
    result = dp(y-1, x);
    for(int i=0;i<=x;i++){
      // cout << "y-1>=0 " << i << " " << x << endl;
      result += data[y][i];
    }
  }else if(x-1>=0){
    result = dp(y, x-1);
    for(int i=0;i<=y;i++){
      // cout << "x-1>=0 " << i << " " << x << endl;
      result += data[i][x];
    }
  }else{
    // cout << "0,0 " << y << " " << x << endl;
    result = data[y][x];
  }
  cache[y][x] = result;
  // cout << y << " " << x << " : " << result << endl;
  return result;
}

int main() {

  // problem => sum of subproblems

  // 1,2, 3,3 => (3,3) - (3,1) - (0,3) + (0,1)
  cin >> n >> m >> q;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> data[i][j];
      cache[i][j] = -999;
    }
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++){
  //     cout << data[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for(int i=0;i<q;i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int result = dp(c,d) - dp(c,b-1) - dp(a-1,d) + dp(a-1,b-1);
    cout << result << endl;

  }

  return 0;
}