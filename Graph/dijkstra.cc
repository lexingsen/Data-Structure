/*
 * @Description: dijkstra算法实现  简单版
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-19 08:05:14
 */

#include <bits/stdc++.h>
using namespace std;


const int N=1000+10;
int n,m;
int g[N][N];// 邻接矩阵
int dist[N];
int st[N];


void dijkstra() {
  memset(dist, 0x3f, sizeof(dist));
  int t = -1; 
  
  // 找出剩下点距离远点最近的
  for (int j=1; j<=n; ++j) {
    if (!st[j] && (t==-1 || dist[j]<dist[t])) {
      t = j;
    }
  }

  st[t] = true;
  // 从1号到j号的点能否用经过t的一条路径来更新
  for (int j=1; j<=n; ++j) {
    dist[j] = min(dist[j], dist[t]+g[t][j]);
  }
}




int main() {
  cin >> n >> m;
  while (m --) {
    int a,b,w;
    cin >> a >> b >> w;
    g[a][b] = g[b][a] = min(g[a][b], w);
  }
  dijkstra();
  cout << dist[n] << endl;
  return 0;
}