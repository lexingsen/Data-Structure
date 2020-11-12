#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N=100010;
int a[N], t[N];
ll ans;

void mergeSort(int l, int r) {
  if (l >= r) return;
  int m = r+l>>1;
  mergeSort(l,m);mergeSort(m+1,r);
  for (int k=k,i=l,j=m+1; k<=r; k++) {
    if (j>r || i<=m&&a[i]<=a[j]) t[k] = a[i++];
    else ans += m-i+1, t[k] = a[j++];
  }
  for (int i=l; i<=r; ++i) a[i] = t[i];
}

