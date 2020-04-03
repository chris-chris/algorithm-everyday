#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main() {
  stack <char> mystack;
  char seq[30];
  char original[30];
  scanf("%s", seq);
  int len = strlen(seq);
  int result[100];
  int seq_idx=0, ori_idx=0, result_idx=0;
  while(ori_idx < len && seq_idx < len) {
    if(!mystack.empty() && mystack.top() == seq[seq_idx]) {
      mystack.pop();
      result[result_idx++] = 1;
      seq_idx++;
    }
    else{
      char target = 'a' + ori_idx++;
      mystack.push(target);
      result[result_idx++] = 2;
    }
    // printf("%c", seq[seq_idx]);
    // mystack.push(seq[i]);
  }

  while(!mystack.empty() && mystack.top() == seq[seq_idx]){
    mystack.pop();
    result[result_idx++] = 1;
    seq_idx++;
  }

  if(!mystack.empty()){
    printf("impossible\n");
  }else{
    for(int i=0;i<result_idx;i++){
      if(result[i]==1){
        printf("pop\n");
      }else{
        printf("push\n");
      }
    }
  }


  // printf("%s", seq);

  return 0;
}