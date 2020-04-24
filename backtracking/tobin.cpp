#include <iostream>
using namespace std;

const int MAX = 20;
int data[MAX];
int n, k, cnt=0;

void recursion(int idx){
  if(idx >= n){
    if(cnt == k){
      for(int i=0;i<n;i++){
        cout << data[i];
      }
      cout << endl;
    }
    return;
  }
  for(int i=1;i>=0;i--){
    if(i==1 && cnt + 1 <= k){
      cnt++;
      data[idx] = i;
      recursion(idx+1);
      cnt--;
    }else if(i==0){
      data[idx] = i;
      recursion(idx+1);
    }
  }

}

int main() {

  // n, k
  // n자리 이진 패턴
  cin >> n >> k;

  recursion(0);

  return 0;
}