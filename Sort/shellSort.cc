#include <bits/stdc++.h>
using namespace std;


void shellSort(int *a, int n) {
  int d=1;
  while (d < n/3) d=d*3+1;
  while (d>=1) {
    for (int i=d; i<n; ++i) {
      int x=a[i];
      int j;
      for (j=i; j>=d && a[j-d]>x; j-=d) a[j] = a[j-d];
      a[j] = x;
    }
    d/=3;
  }
}


int main() {
  int a[] = {3,5,4,8,0,1,2,9,7,6};
  int n = sizeof(a)/sizeof(int);
  shellSort(a, n);
  for_each(a, a+n, [](int x) {cout << x << " ";}); cout << endl;
  return 0;
}