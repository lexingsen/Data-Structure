/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 09:25:36
 */
#include <bits/stdc++.h>
using namespace std;


// dist从表示前面的最大跳跃距离  dist>=i

/*
能不能跳出格子
*/
bool canJump(vector<int> &a) {
  int dist = 0;
  for (int i=0; i<a.size() && dist>=i; ++i) {
    dist = max(dist, i+a[i]);
  }
  return dist >= (int)a.size()-1; 
}


