#include <iostream>
using namespace std;

const int MAX = 10100;
long long int n, i, maxn=0;
long long int s[MAX], e[MAX];

long long int count(long long int idx){

  long long int cnt = 0;
  for(long long int x=0;x<n;x++){
    long long int end = idx;
    if(e[x] < idx)
      end = e[x];
    if(idx - s[x] > 0)
      cnt += end - s[x];
  }
  cout << idx << " " << cnt << endl;
  return cnt;
}

int main() {
  cin >> n;
  for(int x=0;x<n;x++){
    cin >> s[x] >> e[x];
    if(maxn < e[x]){
      maxn = e[x];
    }
  }
  cin >> i;
  long long int p=1, q=maxn;
  while(p+1<q){
    long long int mid = (p+q)/2;
    long long int cnt = count(mid);
    if(cnt < i)
      p = mid;
    else if(cnt > i)
      q = mid;
    else{
      p = mid;
      break;
    }

  }
  cout << p << endl;

  return 0;
}