/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 13:07:48
 */
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
int minimumTotal(vector<vector<int>> &a) {
  int n = a.size();
  vector<vector<ll>> f(n, vector<ll>(n, 0));
  f[0][0] = a[0][0];
  for (int i=1; i<n; ++i) {
    for (int j=0; j<=i; ++j) {
      f[i][j] = INT_MAX;
      if (j > 0) f[i][j] = min(f[i][j], f[i-1][j-1]+ a[i][j]);
      if (j < i) f[i][j] = min(f[i][j], f[i-1][j] + a[i][j]);
    
    }
  }min

  ll res = INT_MAX;
  for (int i=0; i<n; ++i) res = min(res, f[n-1][i]);
  return res;
}