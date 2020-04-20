#include <iostream>
using namespace std;

int n;
const int MAX = 100100;
int data[MAX];
int cache[MAX];

int f(int x) {
  if(x >= n) return 0;
  if(cache[x] != -999999)
    return cache[x];

  int a = f(x+1);
  int b = data[x] + f(x+2);
  int c = data[x] + data[x+1] + f(x+3);
  int result;
  if(a >= b && a >= c) result = a;
  else if(b >= a && b >= c) result = b;
  else result = c;
  cache[x] = result;
  return result;
}

int main() {

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> data[i];
    cache[i] = -999999;
  }

  int result = f(0);

  cout << result << endl;

  // f(0) = f(1) + f(2) + f(3)
  // 0 선택 f(2)
  // 0, 1 선택 f(3)
  // 선택안함 f(1)

  return 0;
}