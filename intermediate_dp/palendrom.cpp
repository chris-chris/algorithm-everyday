#include <iostream>
#include <map>
#include <utility>
#include <string.h>
using namespace std;

const int MAX = 1010;
char s[MAX];
int slen;
map<pair<int, int>, int> cache;

int min(int a, int b){
  if(a<b) return a;
  else return b;
}

int dp(int p, int q){
  if (p >= q) return 0;
  pair<int, int> key = make_pair(p, q);

  if(cache.count(key))
    return cache[key];

  int result;
  if(s[p] == s[q]){
    result = dp(p+1, q-1);
  }else{
    result = min(dp(p, q-1) + 1, dp(p+1, q) + 1);
  }
  cache[key] = result;
  // dp(p, q) = 0 if p >= q;
  // dp(p, q) = dp(p+1, q-1); if s[p] == s[q]
  // dp(p, q) = min(dp(p, q-1) + 1, dp(p+1, q) + 1)
  return result;
}

int main() {
  cin >> s;
  slen = strlen(s);
  int ret = dp(0, slen-1);
  //Please Enter Your Code Here
  cout << ret << endl;
  return 0;
}