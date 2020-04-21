#include <iostream>
#include <map>

using namespace std;

int n;
const int MAX = 15;
char data[MAX];
int result[MAX];
bool done = false;
map <int, bool> m;

void f(int idx, int step){
  if(done) return;
  // cout << "f:" << idx << " " << step << endl;
  if(idx > n){
    // cout << idx << " " << n << endl;
    for(int i=0;i<=n;i++)
      cout << result[i];
    cout << endl;
    done = true;
  }

  if(step == 1){
    for(int i=0;i<=9;i++){
      // cout << idx << "m[i]" << i << " " << m[i] << endl;
      if(m[i]) continue;
      if(idx > 0 && data[idx-1] == '>' && result[idx-1] <= i) continue;
      if(idx > 0 && data[idx-1] == '<' && result[idx-1] >= i) continue;

      result[idx] = i;
      m[i] = true;
      f(idx+1, step);
      m[i] = false;

    }
  }else{
    for(int i=9;i>=0;i--){

      if(m[i]) continue;
      if(idx > 0 && data[idx-1] == '>' && result[idx-1] <= i) continue;
      if(idx > 0 && data[idx-1] == '<' && result[idx-1] >= i) continue;

      result[idx] = i;
      m[i] = true;
      f(idx+1, step);
      m[i] = false;

    }

  }

}

int main() {

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> data[i];
  }
  for(int i=0;i<=9;i++) m[i] = false;
  done = false;
  f(0, -1);
  for(int i=0;i<=9;i++) m[i] = false;
  done = false;
  f(0, 1);

  return 0;
}