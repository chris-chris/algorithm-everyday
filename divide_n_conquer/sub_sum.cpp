#include <iostream>

using namespace std;

const int MAX = 100100;
int n;
int data[MAX];

int getSumMax(int start, int end) {
if(start == end) return data[start];
if(n==1) return data[0];

int mid = (start + end) / 2;

int left = getSumMax(start, mid);
int right = getSumMax(mid+1, end);

// 중간부분을 포함하는 연속부분 중 최대합

// 1 8
int leftSum = 0, leftMax = -999999999;
for(int i=mid;i>=start;i--){
  leftSum = leftSum + data[i];

if(leftMax < leftSum)
leftMax = leftSum;
}

int rightSum = 0, rightMax = -999999999;
for(int i=mid+1;i<=end;i++){
  rightSum = rightSum + data[i];

if(rightMax < rightSum)
rightMax = rightSum;
}

int myMax = leftMax + rightMax;
if(left >= right && left >= myMax) return left;
else if(right >= left && right >= myMax) return right;
else return myMax;
}

int main() {
cin >> n;
for(int i=0;i<n;i++){
  cin >> data[i];
}
int result = getSumMax(0, n-1);
cout << result << endl;

return 0;
}