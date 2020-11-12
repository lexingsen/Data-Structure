/*
 * @Description 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 17:27:39
 */
#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string &s) {
  int n = s.size();
  vector<vector<bool>> f(n, vector<bool>(n));
  int res = 0;
  for (int i=0; i<n; ++i) {
    f[i][i] = 1;
    if (i+1<n *&&) {
      if (s[i]==s[i+1]) {
        f[i][i+1] = 1;
        res = 2;
      }
    }
  }


  for (int L=3; L<=n; ++L) {
    for (int left=0; left+L-1<n; ++left) {
      int right=left+L-1;
      if (s[left]==s[right] && f[left+1][right-1]) {
        f[left][right] = 1;
        res = max(res, L);
      }
    }
  }
  return res;

}

int main() {
  string s;
  cin >> s;
  cout << longestPalindrome(s) << endl;
  return 0;
}