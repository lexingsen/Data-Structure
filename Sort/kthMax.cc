/*
 * @Description: 第k大数
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-25 02:45:37
 */
#include <bits/stdc++.h>
using namespace std;

// 第k大数: 在一个乱序数组中从大到小第k个数即为第k大

// int e = a[l]
// a[l+1....j] > e
// a[j+1....i-1] > e
// a[i]当前待考察的元素
int partition(int *a, int l, int r) {
  swap(a[l], a[rand() % (r-l+1)+l]);
  int e = a[l];
  int j = l;
  for (int i=l+1; i<=r; ++i) {
    if (a[i] > e) {
      swap(a[j+1], a[i]);
      j ++;
    }
  }
  swap(a[j], a[l]);
  return j;
}


int kthMax(int *a, int l, int r, int k) {
  if (l == r) return a[l];
  int p = partition(a,l,r);
  int m = p-l+1;
  if (m == k) {
    return a[p];
  } else if (k < m) {
    return kthMax(a,l,p-1,k);
  } else {
    return kthMax(a,p+1,r,k-m);
  }
}



int main() {
  // 1,2,3,4,5,6,7,8
  int a[] = {7,1,2,5,4,8,3,6};
  int n = sizeof(a)/sizeof(n);

  cout << 8 << " is the " << kthMax(a,0,n-1,8) << "th big" << endl;
  cout << 1 << " is the " << kthMax(a,0,n-1,1) << "th big" << endl;
  cout << 3 << " is the " << kthMax(a,0,n-1,3) << "th big" << endl;
  return 0;
}