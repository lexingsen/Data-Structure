/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-27 05:33:11
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      int fives=0, tens=0;
      for (auto b:bills) {
        if (b == 5) {
          fives ++;
        } else if (b == 10) {
          tens ++;
          if (!fives) return false;
          fives --;
        } else {
          int t = 15;
          if (tens) {
            t -= 10;
            tens --;
          }
          while (t && fives) {
            t -= 5;
            fives --;
          }
          if (t) return false;
        }
      }
      return true;
    }
};