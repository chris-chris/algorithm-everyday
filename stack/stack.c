#include <stdio.h>

struct Stack{
  int capacity;
  int data[1000];
  int len=0;
  void create(int y){
    capacity = y;
  }
  void push(int y){
    if(len>=capacity){
      printf("Overflow\n");
    }else{
      data[len++] = y;
      //printf("push %d to %d\n", y, len);
    }
  }
  void pop(){
    if(len<=0){
      printf("Underflow\n");
    }else{
      data[len--] = 0;
    }
  }
  int top(){
    if(len<=0){
      return -1;
    }else{
      return data[len-1];
    }
  }
};

int n, m, a, b;

int main() {
  scanf("%d %d", &n, &m);
  Stack stack;
  stack.create(n);
  for(int i=0;i<m;i++){
    int a, b;
    scanf("%d", &a);

    if(a==1){
      scanf("%d", &b);
      stack.push(b);
    }else if(a==2){
      stack.pop();
    }else{
      int result = stack.top();
      if(result == -1){
        printf("NULL\n");
      }else{
        printf("%d\n", result);
      }
    }
  }
  return 0;
}