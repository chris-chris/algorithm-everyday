#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

int main() {

  stack <int> mystack;
  char mystring[100];
  bool result = true;

  scanf("%s", mystring);
  int len = strlen(mystring);
  // printf("%s %d", mystring, len);

  for(int i=0;i<len;i++){
    if(mystring[i] == '('){
      mystack.push(i);
    }else if(!mystack.empty()){
      mystack.pop();
    }else{
      result = false;
      break;
    }
  }
  if(!mystack.empty()){
    result = false;
  }
  if(result){
    printf("YES\n");
  }else{
    printf("NO\n");
  }

  return 0;
}