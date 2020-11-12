/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-11-09 22:27:17
 */
#include <bits/stdc++.h>
using namespace std;

const int N=100;
const int inf=0x3f3f;
int n, G[N][N];
bool visited[N]={false};

void dfs(int u, int depth) {
  visited[u] = true;
  for (int i=0; i<n; ++i) {
    if (visited[i]==false && G[u][i] != inf) {
      dfs(i, depth+1);
    }
  }
}


void dfs() {
  for (int i=0; i<n; ++i) {
    if (visited[i] == false) dfs(i, 1);
  }
}