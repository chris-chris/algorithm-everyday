#include <iostream>
#include <string.h>
#include <map>
#include <utility>
using namespace std;

int lena, lenb;
const int MAX = 1010;
char A[MAX], B[MAX];
map<pair<int, int>, int> cache;

int min(int a, int b){
  if(a>b) return b;
  else return a;
}

int f(int p, int q){
  pair<int,int> key = make_pair(p, q);
  if(cache.count(key))
    return cache[key];
  int result;

  // cout << "f("<< p << q << ")"<< endl;
  if(p>=lena && q>=lenb) {
    result = 0;
  } else if(p>=lena && q<lenb){
    result = f(p, q+1) + 1;
  }else if(A[p] == B[q]) {
  // f(p, q) = f(p, q+1) + 1
    result = f(p+1, q+1);
  }else {
    result = min(f(p, q+1) + 1, f(p+1, q) + 1);
  }
  cache[key] = result;
  // f(p, q) = f(p+1, q+1) if A[p] == B[q]
  return result;
  // f(p, q) = min(f(p, q+1) + 1, f(p+1, q) + 1))

}

int main() {
  // cin >> n;
  cin >> A;
  cin >> B;
  lena = strlen(A);
  lenb = strlen(B);
  // A ~ B
  int ret = f(0,0);
  cout << ret << endl;

  return 0;
}