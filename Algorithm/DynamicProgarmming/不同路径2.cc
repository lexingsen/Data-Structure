/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 13:24:42
 */

#include <bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& g) {
  int n = g.size(), m = g[0].size();
  vector<vector<int>> f(n, vector<int>(m));
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      if (g[i][j]) continue;
      if (!i && !j) f[i][j] = 1;
      if (i > 0) f[i][j] += f[i-1][j];
      if (j > 0) f[i][j] += f[i][j-1];
    }
  }
  return f[n-1][m-1];
}