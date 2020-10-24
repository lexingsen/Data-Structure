/*
 * @Description: 冒泡排序及优化
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-24 23:48:51
 */
#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int *a, int n) {
  int i,j;
  bool flag=false;
  for (i=0; i<n-1; ++i) {
    flag=false;
    for (j=0; j<n-1-i; ++j) {
      if (a[j] > a[j+1]) {
        flag=true;
        swap(a[j], a[j+1]);
      }
    }
    if (!flag) break;
  }
}



