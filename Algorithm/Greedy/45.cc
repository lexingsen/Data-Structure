/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 09:25:40
 */



#include <bits/stdc++.h>
using namespace std;


/*
最少跳跃几步就能跳出格子
f[i]数组是单调递增
反证法：
假设f[i] > f[i+1]
j -> i+1
则j+a[j] >= i+1，则一定存在j+a[j]>=i

每次只能跳一步
f[] = {0,0,0,0,1,1,1,1,2,2,2,3,3,4,4,4,5}

*/

class Solution {
public:
  int jump(vector<int> &a) {
    if (a.size() == 1) return 0;
    // 区间
    int l=0,r=0,step=0;
    while (l <= r) {
      int max_r = 0;
      for (int i=l; i<=r; ++i) {
        max_r = max(max_r, i+a[i]);
      }
      step ++;
      l = r+1, r=max_r;
    }
    return step;
  }  
};