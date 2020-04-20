#include <iostream>

using namespace std;

const int MAX = 105;
int cache[MAX];
int n;

int main() {

  cin >> n;

  cache[1] = 1;
  cache[2] = 2;
  for(int i=3;i<=n;i++){
    cache[i] = cache[i-1] + cache[i-2];
    cache[i] = cache[i] % 1000007;
  }
  cout << cache[n] << endl;

  return 0;
}