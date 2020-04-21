#include <iostream>
using namespace std;

int n;
const int MAX = 1000100;
int data[MAX];
int result[MAX];

int max(int a, int b){
  if(a>b) return a;
  else return b;
}

int main() {

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> data[i];
  }

  result[0] = data[0];

  for(int i=1;i<n;i++){
    // f(i) = max(f(i-1)+data[i], data[i])
    result[i] = max(result[i-1] + data[i], data[i]);
  }
  int final = -999999999;
  for(int i=0;i<n;i++){
    if(result[i]>final)
      final = result[i];
  }
  cout << final << endl;

  return 0;
}