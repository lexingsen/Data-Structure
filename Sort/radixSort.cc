/*
 * @Description: 基数排序实现
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-25 03:19:04
 */
#include <bits/stdc++.h>
using namespace std;


/*
基数排序基于分配与收集
时间复杂度O(d(n+r))
空间复杂度O(r)

基数排序有局限性
稳定
与初始状态无关
*/

// 获取第i位的元素
int getBit(int x, int i) {
  while (i --) x/=10;
  return x%10;
}

// n表示数组的长度    d表示有几位   如122 三位
void radixSort(int *a, int n, int d) {
  queue<int> q[10];
  for (int i=0; i<d; ++i) {
    // 收集
    for (int j=0; j<n; ++j) {
      q[getBit(a[j], i)].push(a[j]);
    }
    // 分配
    for (int j=0,k=0; j<10; ++j) {
      while (!q[j].empty()) {
        a[k ++] = q[j].front();q[j].pop();
      }
    }
  }
}



int main() {
  int a[] = {31,23,21,45,87,79,64,33,45};
  int n = sizeof(a)/sizeof(int);
  radixSort(a,n,2);
  for_each(a, a+n, [](int x) {cout << x << " ";}); cout << endl;
  return 0;
}