#include <iostream>
#include <map>
#include <utility>

using namespace std;

int n;
// const int MAX = 100100;
// int data[MAX];
// map<pair<int,int>, int> myMap;
map<int, int> cache;

// int dp(int index, int mySum, int k){
//   if(k > 3 && cache.count(k-1) > 0 && cache.count(k-2) > 0 && cache.count(k-3) > 0){
//     return cache[k-1] + cache[k-2] + cache[k-3];
//   }
//   // pair<int,int> key = make_pair(index, mySum);
//   // // cout << "key " << key << endl;
//   // if(myMap.count(key)){
//   //   // cout << "cache hit " << endl;
//   //   return myMap[key];
//   // }
//   if(mySum == n){
//     return 1;
//   }
//   int cnt = 0;
//   int remain = n - mySum;
//   if(index == 0) remain = n - mySum - 1;
//   if(remain >= 3) remain = 3;
//   for(int i=1;i<=remain;i++){
//     // data[index] = i;
//     cnt += dp(index+1, mySum + i, k);
//   }
//   cnt = cnt % 1000007;
//   // myMap[key] = cnt;
//   return cnt;
// }

int main() {

  // 1. problem => subproblems
  // dp(index, mySum) => counts
  // n: 4
  // 0, 0
  // n:4 => sub(3) + sub(2) + subz(1)
  // n:k => sub(k-1) + sub(k-2) + sub(k-3)

  // 2. use subproblems as it is solved already
  // 3. merge it
  cache[1] = 1;
  cache[2] = 2;
  cache[3] = 4;
  cin >> n;
  int cnt = 0;
  for(int i=4;i<=n;i++){
    // cnt = dp(0, 0, i);
    cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
    cache[i] = cache[i] % 1000007;
    // cout << i << " " << cache[i] << endl;
  }

  cout << cache[n] << endl;

  return 0;
}