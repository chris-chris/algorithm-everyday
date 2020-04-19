#include <stdio.h>

int result[30];
int cnt;
int n;

void getResult(int mySum, int index) {
  // 현재까지 구한 합이 mySum이다.
  // 그리고 지금, index 번째 숫자를 결정할 차례, result[index]
  if(mySum == n){
    for(int i=0;i<index;i++){
      if(i>0) printf("+");
      printf("%d", result[i]);
    }
    printf("\n");
    cnt++;
  }else{
    int myNumber;
    if(index == 0) myNumber = n-1;
    else myNumber = n - mySum;

    for(int i=myNumber;i>=1;i--){
      result[index] = i;

      if(index>0 && result[index-1] < result[index]) continue;

      getResult(mySum+i, index+1);

    }
  }
}

int main() {

  cnt = 0;
  scanf("%d", &n); // n = 5

  getResult(0, 0);

  printf("%d", cnt);

  return 0;
}