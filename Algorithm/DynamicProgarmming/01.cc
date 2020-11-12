/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 18:20:36
 */
#include <bits/stdc++.h>
using namespace std;


const int N=1010;

int v[N],w[N],f[N][N];

int main() {
  int n,m;
  cin >> n >> m;
  for (int i=1; i<=n; ++i) cin >> v[i] >> w[i];
  f[0][0] = 0;
  for (int i=1; i<=n; ++i) {
    for (int j=0; j<=m; ++j) {
      f[i][j] = f[i-1][j];
      if (j >= v[i]) {
        f[i][j] = max(f[i][j], f[i-1][j-v[i]]+w[i]);
      }
    }
  }

  int res = INT_MAX;
  for (int i=1; i<=n; ++i) {
    res = max(res, f[n][i]);
  }
  return 0;
}