#include <bits/stdc++.h>
using namespace std;


// 递归  非递归  逆序数个数


// a[l...m-1]  a[m...r]

void merge(int *a, int l, int m, int r) {
  int leftsize = m-l;
  int rightsize = r-m+1;
  int *left = new int[leftsize];
  int *right = new int[rightsize];
  for (int i=l; i<m; ++i) left[i-l] = a[i];
  for (int i=m; i<=r; ++i) right[i-m] = a[i];
  int i=0,j=0,k=l;
  while (i < leftsize && j < rightsize) {
    if (left[i] < right[j]) {
      a[k ++] = left[i ++];
    }
    else { 
      a[k ++] = right[j ++];
    }
  } 
  while (i < leftsize)  a[k ++] = left[i ++];
  while (j < rightsize) a[k ++] = right[j ++];
  delete[] left;
  delete[] right;
}

void mergeSort(int *a, int l, int r) {
  if (l >= r) return;
  int m = (r+l)/2;
  mergeSort(a, l, m);
  mergeSort(a, m+1, r);
  merge(a, l, m+1, r);
}


void mergeSortBU(int *a, int n) {
  for (int sz=1; sz<=n; sz+=sz) {
    for (int i=0; i+sz<n; i+=sz+sz) {
      // i...i+sz-1    i+sz...i+sz+sz-1
      merge(a, i, i+sz, min(i+sz+sz-1, n-1));
    }
  }
}

const int N=1e5+10;
int t[N];
int res = 0;

// 逆序数对数
void invertPairs(int *a, int l, int r) {
  if (l >= r) return;
  int m = (r+l)/2;
  invertPairs(a,l,m);
  invertPairs(a,m+1,r);
  int i=l, j=m+1, k=0;
  while (i <= m && j <= r) {
    if (a[i] <= a[j]) {
      t[k ++] = a[i ++];
    } else {
      res = m-i+1;
      t[k ++] = a[j ++];
    }
  }
  while (i <= m) t[k ++] = a[i ++];
  while (j <= r) t[k ++] = a[j ++];
  for (int i=l,k=0; i<=r; ++i, ++k) a[i] = t[k];
}


int main() {
  int a[] = {3,5,7,6,8,0,1,9,2,4};
  int n = sizeof(a)/sizeof(int);
  //mergeSort(a, 0, n-1);
  mergeSortBU(a, n);
  for_each(a, a+n, [](int x) {cout << x << " ";});
  return 0;
}