#include <stdio.h>
#include <math.h>
int n;
char data[20];
int sum;
int number[20];
int number2[20];
int cnt;
int value;
void Calculate() {
  int value = 1;
  for(int i = n-2; i >= 0; i--) {
     if(data[i] == '.' && i < 8) {
       value = value * 10;
       number[i] = number[i] * value + number[i+1];
       number[i+1] = 0;
     }
     else if(data[i] == '.' && i >= 8) {
       value = value * 100;
       number[i] = number[i] * value + number[i+1];
       number[i+1] = 0;
     }
     else value = 1;
  }
  sum = number[0];
  for(int i = 0; i < n-1; i++) {
    if(data[i] == '+' || data[i] == '.') {
      sum += number[i+1];
    }
    else if(data[i] == '-') {
      sum -= number[i+1];
    }
  }
  if(sum == 0) {
    cnt++;
    if(cnt <= 20) {
      printf("1");
      for(int i = 0; i < n-1; i++) printf(" %c %d", data[i], i+2);
      printf("\n");
    }
  }
}
void getResult(int x) {
  if(x == n-1) {
    for(int i = 0; i < n; i++) number[i] = i+1;
    Calculate();
  }
  else {
    for(int i = 0; i < 3; i++){
     if(i == 0) {
       data[x] = '+';
       getResult(x+1);
     }
     else if(i == 1) {
       data[x] = '-';
       getResult(x+1);
     }
     else {
       data[x] = '.';
       getResult(x+1);
     }
    }
  }
}
int main() {
  scanf("%d", &n);
  getResult(0);
  printf("%d\n", cnt);
  return 0;
}