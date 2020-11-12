/*
 * @Description
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 09:45:57
 */

#include <bits/stdc++.h>
using namespace std;


int wiggleMaxLength(vector<int> &a) {
  // 去掉相同元素
  a.erase(unique(a.begin(), a.end()), a.end());
  if (a.size() <= 2) return a.size();
  int res = 0;
  for (int i=1; i<a.size()-1; ++i) {
    int u=a[i-1],v=a[i],w=a[i+1];
    if (u<v && w<v) res ++;
    else if (v<w && v<u) res ++;
  }
  return res;
}