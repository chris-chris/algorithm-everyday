#include <iostream>
using namespace std;

const int MAX = 10100;
long long int n, i, maxn=0;
long long int s[MAX], e[MAX];

long long int count(long long int number){
  // input number:
  // 1 4
  // 3 5
  // number: 4
  // return: 1~4 => 4
  // 3~4 => 2
  // 6 numbers smaller than or equal to 4
  long long int cnt = 0;
  for(int i=0;i<n;i++){

    long long int number_or_end = number;
    if(number >= e[i]) number_or_end = e[i];

    long long int diff = number_or_end - s[i] + 1;
    if(diff > 0)
      cnt += diff;

  }
  return cnt;
}

int main() {
  long long int maxe=0;
  cin >> n;
  long long int target;
  for(int i=0;i<n;i++){
    cin >> s[i] >> e[i];
    if(e[i]>=maxe)
      maxe = e[i];
  }
  cin >> target;
  // 1 4
  // 3 5
  // 3

  // 1 2 3 4
  // 3 4 5
  // 1 2 3 3 4 4 5
  // 0 1 2 3
  // => 3
  long long int p, q, cnt, result;
  p = 1;
  q = maxe;
  cnt = 0;
  result = 0;
  cnt = count(p);
  // p=1 q=5
  //
  while(p+1<q){
     long long int mid = (p+q)/2;
     // p=1 q=5 mid=3
     cnt = count(mid); // count(3) = 4
     if(cnt == target+1) { // exact
       // cout << "exact" << mid << " " << cnt << " " << target+1 << endl;
       p = mid;
       break;
     }else if(cnt < target+1){
       // cout << "cnt < target " << p << " " << q << " " << mid << " " << cnt << " " << target+1 << endl;
       p = mid;
     }else{
       // cout << "cnt > target " << p << " " << q << " " << mid << " " << cnt << " " << target+1 << endl;
       q = mid;
     }
     // 1 2 3
     // 2 3 4 5 6 7 8 9 10
     // 1 2 3 4 5 6 7 8
     // 1 1 2 2 2 3 3 3 4 4 5 5 ...
     // 0 1 2 3 4 5 6 7 8 9 10 11


  }
  if(p+1 == q)
    cout << p+1 << endl;
  else
    cout << p << endl;

  return 0;
}