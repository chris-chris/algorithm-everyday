#include <iostream>
#include <map>
#include <utility>

using namespace std;

const int MAX = 100100;
int n;
int red[MAX], green[MAX], blue[MAX];

map<pair<int, int>, int> myMap;

int dp(int x, int color){
  if(x>=n) return 0;
  pair<int,int> key = make_pair(x, color);
  if(myMap.count(key))
    return myMap[key];
  // red: 0 green: 1 blue: 2

  int a, b, c;

  if(color == 0) a = 0;
  else a = red[x] + dp(x+1, 0);

  if(color == 1) b = 0;
  else b = green[x] + dp(x+1, 1);

  if(color == 2) c = 0;
  else c = blue[x] + dp(x+1, 2);

  int result;
  if(a >= b && a >= c) result = a;
  else if(b >= a && b >= c) result = b;
  else result = c;
  myMap[key] = result;
  return result;
}

int main() {

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> red[i] >> green[i] >> blue[i];
  }
  int a = red[0] + dp(1, 0);
  int b = green[0] + dp(1, 1);
  int c = blue[0] + dp(1, 2);
  int result;
  if(a >= b && a >= c) result = a;
  else if(b >= a && b >= c) result = b;
  else result = c;

  cout << result << endl;

  return 0;
}