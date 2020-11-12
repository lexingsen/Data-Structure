/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 12:34:37
 */
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &a) {
  int n = a.size();
  int res = INT_MIN, last=0;
  for (int i=0; i<n; ++i) {
    int now = max(last, 0) + a[i];
    res = max(res, now);
    last = now;
  }
  return res;
}
