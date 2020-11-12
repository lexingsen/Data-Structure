/*
 * @Description
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 10:51:11
 */
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
bool cmp(const pii &a, const pii &b) {
  return a.second < b.second;
}


int findMinArrowShots(vector<pii> &points) {
  sort(points.begin(), points.end(), cmp);
  int res = 0, r = INT_MIN;
  if (points.size() >= 1 && points[0].first == INT_MIN) res ++;
  for (auto p:points) {
    if (p.first > r) {
      r = p.second;
      res ++;
    }
  }

  return res;
}
