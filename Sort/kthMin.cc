/*
 * @Description: 第k小数字
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-25 02:45:44
 */
#include <bits/stdc++.h>
using namespace std;

/*
策略：第k小数 就是求解乱序数组中从小到大第k个数
*/

// a[l+1...j] < e 
// a[j+1...i-1] > e
// a[i]为当前待考察元素

// 时间复杂度O(n)
int partition(int *a, int l, int r) {
  swap(a[l], a[rand() % (r-l+1)+l]);
  int e = a[l];
  int j = l;
  for (int i=l+1; i<=r; ++i) {
    if (a[i] < e) {
      swap(a[j+1], a[i]);
      j ++;
    }
  }
  swap(a[j], a[l]);
  return j;
}



int kthMin(int *a, int l, int r, int k) {
  if (l == r) return a[l];
  int p = partition(a,l,r);
  int m = p-l+1;
  if (k == m) {
    return a[p];
  } else if (k < m) {
    return kthMin(a,l,p-1,k);
  } else {
    return kthMin(a,p+1,r,k-m);
  }
}

void quickSort(int *a, int l, int r) {
  if (l>=r) return;
  int p = partition(a,l,r);
  quickSort(a,l,p-1);
  quickSort(a,p+1,r);
}


int main() {
  int a[] = {3,5,6,1,4,2}; // 1,2,3,4,5
  int n = sizeof(a)/sizeof(int);
  quickSort(a,0,n-1);
  for_each(a,a+n, [](int x) {cout << x << " ";});
  cout << 1 << " is " << kthMin(a,0,n-1,1) << "th" << endl;
  cout << 3 << " is " << kthMin(a,0,n-1,3) << "th" << endl;
  cout << 5 << " is " << kthMin(a,0,n-1,5) << "th" << endl;
  return 0;
}