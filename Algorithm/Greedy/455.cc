/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-27 09:01:55
 */
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // g表示胃口   s表示饼干的尺寸
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(), g.end());
      sort(s.begin(), s.end());
      int i=0,j=0,res=0;
      while (i < g.size() && j < s.size()) {
        if (g[i] <= s[j]) {
          res ++;
          i ++;
          j ++;
        } else {
          j ++;
        }
      }

      return res;
    }
};