/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 15:44:31
 */
#include <bits/stdc++.h>
using namespace std;



int LIS(vector<int> &a) {
  int n = a.size();
  vector<int> f(n);
  for (int i=0; i<n; ++i) {
    f[i] = 1;
    for (int j=0; j<n; ++j) {
      if (a[j] < a[i]) {
        f[i] = max(f[j]+1, f[i]);
      }
    }
  }
  int res = INT_MIN;
  for (int i=0; i<n; ++i) res = max(res, f[i]);
  return res;
}

int lengthOfLIS(vector<int> nums) {
  int n = nums.size();
  vector<int> f(n);
  for (int i=0; i<n; ++i) {
    f[i] = 1;// 以自己为1类   最长不下降子序列长度为1
    for (int j=0; j<n; ++j) {
      if (nums[j]<=nums[i]) {
        f[i] = max(f[j]+1, f[i]);
      }
    }
  }
  int res = 0;
  for (int i=0; i<n; ++i) res = max(res, f[i]);
  return res;
}