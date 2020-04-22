#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
using namespace std;

int n;
const int MAX = 30;
char data[MAX][MAX];
bool check[MAX][MAX] = {0, };
vector<int> result;
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int y, int x){
  if(y < 0 || y >= n) return false;
  if(x < 0 || x >= n) return false;
  if(check[y][x]) return false;
  if(data[y][x] == '0') return false;
  return true;
}

int bfs(int y, int x){
  pair<int, int> key = make_pair(y, x);
  queue<pair<int, int>> Queue;
  Queue.push(key);
  check[y][x] = true;
  int result = 1;
  while(!Queue.empty()){
    key = Queue.front();
    Queue.pop();
    y = key.first;
    x = key.second;
    for(int i=0;i<4;i++){
      int dy = dirs[i][0];
      int dx = dirs[i][1];
      int y2 = y + dy;
      int x2 = x + dx;
      if(isValid(y2, x2)){
        pair<int, int> key2 = make_pair(y2, x2);
        Queue.push(key2);
        check[y2][x2] = true;
        result++;
      }
    }
  }
  return result;
}

vector<int> merge(vector<int> left, vector<int> right){
  vector<int> result;
  int l=0, r=0;
  while(l<left.size() && r<right.size()){
    if(left[l] < right[r])
      result.push_back(left[l++]);
    else
      result.push_back(right[r++]);
  }

  while(l<left.size()){
    result.push_back(left[l++]);
  }
  while(r<right.size()){
    result.push_back(right[r++]);
  }
  return result;
}

vector<int> mergeSort(vector<int> result){
  int size = result.size();
  if(size <= 1) return result;
  int mid = size/2;
  vector<int> left(result.begin(), result.begin()+mid);
  vector<int> right(result.begin()+mid, result.end());
  return merge(mergeSort(left), mergeSort(right));
}

int main() {

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> data[i];
    // for(int j=0;j<n;j++){
    //   cin >> data[i][j];
    // }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      // cout << i << "," << j << ":" << check[i][j] << "&&" << data[i][j];
      if(check[i][j] == false && data[i][j] == '1'){
        int r = bfs(i,j);
        result.push_back(r);
        // cout << "valid" << r;
      }
      // cout << endl;
    }
  }
  result = mergeSort(result);

  cout << result.size() << endl;
  for(int i=0;i<result.size();i++){
    cout << result[i] << endl;
  }

  return 0;
}