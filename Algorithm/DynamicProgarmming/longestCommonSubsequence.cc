#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {

  }
};


// 递归
/*
1.n=-1 或 m=-1  取空序列
2.a[n] == 'x' == b[m]
  lcs(a[0..n), b[0...m)) + 'x'
3.a[n] != b[m] max(lcs(a[0..n], b[0...m)), lcs(a[0..n), b[0...m]))
*/