#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1010;
vector <int> data[MAX];

vector<int> merging(vector<int> left, vector<int> right){
  vector<int> result;
  int lsize = left.size();
  int rsize = right.size();
  if(lsize == 0 && rsize > 0) return right;
  if(rsize == 0 && lsize > 0) return left;
  if(lsize == 0 && rsize == 0) return left;
  int l=0;
  int r=0;
  while(l<lsize && r<rsize){
    if(left[l] < right[r]){
      result.push_back(left[l++]);
    }else{
      result.push_back(right[r++]);
    }
  }
  while(l<lsize){
    result.push_back(left[l++]);
  }
  while(r<rsize){
    result.push_back(right[r++]);
  }
  return result;
}

vector<int> mergeSort(vector<int> arr){
  int size = arr.size();
  if(size <= 1) return arr;
  int mid = size/2;

  vector<int> left(arr.begin(), arr.begin()+mid);
  vector<int> right(arr.begin()+mid, arr.end());

  return merging(mergeSort(left), mergeSort(right));
}

int main(){
  vector<int> test;
  test.push_back(3);
  test.push_back(2);
  test.push_back(5);
  test.push_back(1);
  test = mergeSort(test);
  for(int i=0;i<test.size();i++){
    cout << test[i] << " ";
  }
}