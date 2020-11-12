/*
 * @Description: kruskal算法实现  
 * @Language: 
 * @Author: 
 * @Date: 2020-10-19 08:05:30
 */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int M=1e5+10;
const int INF=0xffff3838;
int n,m;
int father[N];

int find(int x) {
  int a = x;
  while (x != father[x]) x = father[x];
  while (a != father[a]) {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}

struct Edge {
  int a,b,w;
  bool operator< (const Edge &W) const {
    return w < W.w;
  }
};

Edge edges[M];


int kruskal() {
  sort(edges, edges+m);
  for (int i=1; i<=N; ++i) father[i] = i;
  int res = 0;
  int cnt = 0;
  for (int i=0; i<m; ++i) {
    int a = edges[i].a;
    int b = edges[i].b;
    int w = edges[i].w;
    int fa = find(a), fb = find(b);
    if (fa != fb) {
      father[fa] = fb;
      cnt ++;
      res += w;
    }
  }

  if (cnt < n-1) return INF;
  return res;
}

