/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-27 05:33:58
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
      int k=0;
      for (int i=0; i<t.size() && k<s.size(); ++i) {
        if (s[i] == t[k]) k ++;
      }
      return k == s.size();
    }
};