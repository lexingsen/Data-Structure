/*
 * @Description: 折半插入排序
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-25 03:29:48
 */
#include <bits/stdc++.h>
using namespace std;


// 折半插入排序减少了比较的次数


void binaryInsertSort(int *a, int n) {
  for (int i=1; i<n; ++i) {
    int l=0,r=i-1;
    while (l <= r) {
      int m=(r+l)/2;
      if (a[i] <= a[m]) r = m-1;
      else l = m+1;
    }
    int x = a[i];
    for (int j=i; j>l; j--) a[j] = a[j-1]; 
    a[l] = x; 
  }
}


int main() {
  return 0;
}