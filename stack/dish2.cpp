#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

const int MAX = 100;
stack<char> st;
char str[MAX];
char str2[MAX];
int result[MAX];
int n;

int main() {
  // bacd
  cin >> str;
  n = strlen(str);
  char target = 'a';
  for(int i=0;i<n;i++){
    str2[i] = target++;
  }
  int idx = 0, result_idx=0;
  for(int i=0;i<n;i++){
    result[result_idx++] = 1;
    st.push(str2[i]);
    while(!st.empty() && st.top() == str[idx]){
      result[result_idx++] = -1;
      st.pop();
      idx ++;
    }
  }
  if(!st.empty()){
    cout << "impossible" << endl;
  }else{
    for(int i=0;i<result_idx;i++){
      if(result[i]==1) cout << "push" << endl;
      if(result[i]==-1) cout << "pop" << endl;
    }
  }

  return 0;
}