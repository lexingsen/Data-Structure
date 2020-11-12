/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 10:06:48
 */
#include <bits/stdc++.h>
using namespace std;


using pii=pair<int, int>;
bool cmp(const pii &a, const pii& b) {
  return a.first > b.first || a.first==b.first && a.second<b.second;
}

vector<pii> reconstructQueue(vector<pii>& people) {
  sort(people.begin(), people.end(), cmp);
  vector<pii> res;
  for (auto p:people) {
    res.insert(res.begin()+p.second, p);
  }

  return res;
}



