/*
 * @Description:  
 * @Language: 
 * @Author: 
 * @Date: 2020-10-19 18:40:57
 */
#include <bits/stdc++.h>
using namespace std;


const int N=100;
vector<int> G[N];

int n,m,inDegree[N];

bool toplogicalSort() {
  int num = 0;
  queue<int> q;
  for (int i=0; i<n; ++i) {
    q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();q.pop();
    for (int i=0; i<G[u].size(); ++i) {
      int v = G[u][i];
      inDegree[v] --;
      if (inDegree[v] == 0) {
        q.push(v);
      }
    }
    G[u].clear();
    num ++;
  }
  return num == n;

}


