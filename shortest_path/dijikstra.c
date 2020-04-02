#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100;

vector <int> graph[MAX];
vector <int> cost[MAX];

int n, m, start, end;

int main(){
  scanf("%d %d %d %d", &n, &m, &start, &end);

  for(int i=0;i<m;i++){
    int a,b,c;

    scanf("%d %d %D", &a, &b, &c);

    graph[a].push_back(b);
    graph[b].push_back(a);
    cost[a].push_back(c);
    cost[b].push_back(c);

  }

  for(int i=0;i<n;i++) Table[i] = 99999999;
  Table[0] = 0;

  for(int i=0;i<n;i++){
    int minValue = 9999999, minIndex = -1;
    for(int j=0;j<n;j++){
      if(!Check[j] && minValue > Table[j]) {
        minValue = Table[j];
        minIndex = j;
      }
    }
    Check[minIndex] = true;
    for(int j=0;j<graph[minIndex].size();j++){
      int Node2 = graph[minIndex][j];
      int Cost2 = cost[minIndex][j];

      if(Table[Node2]> Table[minIndex] + Cost2){
        Table[Node2] = Table[minIndex] + Cost2;
      }
    }
  }
  printf("%d\n", Table[end2]);
  return 0;
}