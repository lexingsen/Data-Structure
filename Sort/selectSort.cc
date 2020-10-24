/*
 * @Description: 选择排序 双向选择排序
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-25 00:43:25
 */

/*
不稳定
空间复杂度O(1)
移动次数 最多不会超过3(n-1) 最小0次
比较次数 n(n-1)/2
*/

#include <bits/stdc++.h>
using namespace std;

void selectSort(int *a, int n) {
  for (int i=0; i<n; ++i) {
    int minIndex=i;
    for (int j=i+1; j<n; ++j) {
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    if (i != minIndex) swap(a[i], a[minIndex]);
  }
}


void doubleSelectSort(int *a, int n) {
  int l=0, r=n-1;
  while (l < r) {
    int minIndex = l;
    int maxIndex = n-1;
    if (a[minIndex] > a[maxIndex]) swap(a[minIndex], a[maxIndex]);
    for (int i=l+1; i<=r-1; ++i) {
      if (a[i] < a[minIndex]) minIndex = i;
      else if (a[i] > a[maxIndex]) maxIndex = i;
    }
    if (l != minIndex) swap(a[l], a[minIndex]);
    if (r != maxIndex) swap(a[r], a[maxIndex]);
    l ++, r--;
  }
}