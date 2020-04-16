#include <stdio.h>

int n;
const int MAX = 200100;
int data[MAX];

int abs(int value) {
  if(value<0) return -value;
  else return value;
}

int binarySearch(int target, int start, int end) {
  //printf("binarySearch %d %d %d\n", target, start, end);
  int p = start;
  int q = end;
  if(target == data[start]) return start;
  if(target == data[end]) return end;

  while(p+1 < q){
    int mid = (p + q)/2;
    if(data[mid] < target){
      p = mid+1;
    }else if(data[mid] > target){
      q = mid-1;
    }else{
      return mid;
    }
  }
  // -99 -2 1 4 98
  // target: 99 / -2 1 4 98
  // target: 99 / p: 1, -2 q: 4, 98 mid: 2, 1
  // target: 99 / p: 3, 4 q: 4, 98 mid: 3, 4
  // stop
  if(abs(target - data[p]) < abs(target - data[q])){
    return p;
  }else{
    return q;
  }
  return p;

}

void merging(int data[], int s1, int e1, int s2, int e2) {
  int p=s1;
  int q=s2;
  int tmp[MAX];
  int idx=s1;
  while(p <= e1 && q <= e2){
    if(data[p] < data[q]){
      tmp[idx++] = data[p++];
    }else{
      tmp[idx++] = data[q++];
    }
  }

  while(p <= e1){
    tmp[idx++] = data[p++];
  }
  while(q <= e2){
    tmp[idx++] = data[q++];
  }
  for(int i=s1;i<=e2;i++){
    data[i] = tmp[i];
  }
}

void mergeSort(int data[], int start, int end) {
  if(start >= end) return;

  int mid = (start+end)/2;
  mergeSort(data, start, mid);
  mergeSort(data, mid+1, end);

  merging(data, start, mid, mid+1, end);

}

int main() {

  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &data[i]);
  }

  mergeSort(data, 0, n-1);
  // for(int i=0;i<n;i++){
  //   printf("%d ", data[i]);
  // }
  int minValue = 1000000000;
  int minX = -1;
  int minY = -1;
  for(int i=0;i<n-1;i++){
    int ret = binarySearch(0 - data[i], i+1, n-1);
    int result = abs(data[i] + data[ret]);
    // printf("result: %d %d %d\n", i, ret, result);
    if(result < minValue){
      minValue = result;
      minX = i;
      minY = ret;
    }else if(result == minValue && minX != -1 && data[i] < data[minX]){
      minValue = result;
      minX = i;
      minY = ret;
    }
  }
  printf("%d %d\n", data[minX], data[minY]);

  return 0;
}