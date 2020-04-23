#include <iostream>
#include <map>
#include <utility>
#include <queue>
using namespace std;

const int MAX = 100100;
bool check[MAX];

int bfs(int n, int k){
  queue<int> Queue;
  Queue.push(k);
  check[k] = true;
  while(!Queue.empty()){
    int target = Queue.front();
    int current;
    Queue.pop();
    for(int i=0;i<2;i++){
      if(i==0){ // *2
        current = target * 2;
      }else{
        current = target / 3;
      }
      if(current == 0) continue;
      if(current > n) continue;

      if(!check[current]){
        // cout << current << " ";
        Queue.push(current);
        check[current] = true;
      }
    }
  }
  int cnt = 0;
  for(int i=1;i<=n;i++){

    if(check[i]) cnt++;
  }
  // cout << endl;
  return n - cnt;
}

int main() {
  int n, k, result;
  cin >> n >> k;

  result = bfs(n, k);
  cout << result << endl;

  return 0;
}