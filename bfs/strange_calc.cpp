#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n;
const int MAX = 100100;
bool check[MAX];

int bfs(){
  int current = 1;
  if(n == 1) return 0;
  //int cnt = 0;
  queue<pair<int,int>> Queue;
  Queue.push(make_pair(1, 0));
    check[1] = true;
  while(!Queue.empty()){
    pair<int,int> item = Queue.front();
    int target = item.first;
    int idx = item.second;
    Queue.pop();
    for(int i=0;i<2;i++){
      if(i==0){  // Mul
        // cout << "Mul ";
        current = target * 2;
      }else{
        // cout << "Div ";
        current = target / 3;
      }
      if(current >= 100000) continue;
      //cnt++;
      current = current % 100000;

      // cout << target << " " << current << " " << endl;
      if(current == 0) continue;
      if(current == n){
        return idx+1;
      }
      if(check[current]) continue;

      Queue.push(make_pair(current, idx+1));
      check[current] = true;
    }
  }
  return 0;
}

int main() {

  cin >> n;

  int result = bfs();
  cout << result << endl;

  return 0;
}