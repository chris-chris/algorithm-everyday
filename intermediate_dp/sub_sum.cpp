#include <iostream>
using namespace std;

const int MAX = 100100;
int Table[MAX];
int Data[MAX];
int n;

int main() {

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> Data[i];
  }
  Table[0] = Data[0];

  for(int i=1;i<n;i++) {
    if(Table[i-1] + Data[i] > Data[i]) Table[i] = Table[i-1] + Data[i];
    else Table[i] = Data[i];
  }
  int myMax = -999999999;

  for(int i=0;i<n;i++) {
    if(Table[i]>myMax)
      myMax = Table[i];

  }

  cout << myMax << endl;

  //Please Enter Your Code Here

  return 0;
}