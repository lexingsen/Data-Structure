#include <bits/stdc++.h>
using namespace std;


/*
单调递增
非单调删除逆序大的那个
*/

string removeKdigits(string num, int k) {
  string res;
  for (auto c:num) {
    while (res.size() && res.back() > c && k) {
      res.pop_back();
      k --;
    }
    res += c;
  }
  while (k --) {
    res.pop_back();
  }
  int i = 0;
  while (i < res.size() && res[i] == '0') i ++;
  if (i == res.size()) return "0";
  return res.substr(i);

}