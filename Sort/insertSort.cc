/*
 * @Description: 直接插入排序
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-25 03:29:39
 */
#include <bits/stdc++.h>
using namespace std;


/*
稳定
最好  每次插入一个比较一次  不需要移动
最差  比较 i from 2 to n sum(i)  移动 i from 2 to n sum(i+1)
*/


void insertSort(int *a, int n) {
  for (int i=1; i<n; ++i) {
    for (int j=i; j>=1; j--) {
      if (a[j] < a[j-1]) {
        swap(a[j], a[j-1]);
      } else {
        break;
      }
    }
  }
}


void insertSort(int *a, int n) {
  for (int i=1; i<n; ++i) {
    for (int j=i; j>=1 && a[j]<a[j-1]; j--) {
      swap(a[j], a[j-1]); // 移动次数太多
    }
  }
}

void insertSort(int *a, int n) {
  for (int i=1; i<n; ++i) {
    int x = a[i];
    int j;
    for (j=i; j>=1 && a[j-1]>x; --j) {
      a[j] = a[j-1];
    }
    a[j] = x;
  }
  return;
}


int main() {
  return 0;
}