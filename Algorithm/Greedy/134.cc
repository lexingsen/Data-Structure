/*
 * @Description
 * @Language: 
 * @Author: 
 * @Date: 2020-10-28 11:15:07
 */


#include <bits/stdc++.h>
using namespace std;
// 暴力
int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
  int n = gas.size();
  for (int i=0,j; i<n; i+=j+1) {
    int gas_left = 0;
    for (j=0; j<n; ++j) {
      int k = (i+j)%n;
      gas_left += gas[k] - cost[k];
      if (gas_left < 0) break;
    }

    if (j >= n) return i;
  }

  return -1;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

}