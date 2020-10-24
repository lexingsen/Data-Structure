/*
 * @Description: 快速排序 partition  递归非递归
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-24 23:58:34
 */
#include <bits/stdc++.h>
using namespace std;

/*
优化策略：
1.随机选择算法
2.待排序序列基本有序时，选择直接插入排序进行排序
3.三路快排
*/

// a[l+1...j] < e a[j+1...i) > e
int partition1(int *a, int l, int r) {
  swap(a[l], a[rand()%(r-l+1)+l]);
  int e = a[l];
  int j = l;
  for (int i=l+1; i<=r; ++i) {
    if (a[i] > e) {
      swap(a[j+1], a[i]);
      j ++;
    }
  }
  swap(a[l], a[j]);
  return j;
}

int partition2(int *a, int l, int r) {
  swap(a[l], a[rand()%(r-l+1)+l]);
  int e = a[l];
  while (l < r) {
    while (l < r && a[r] >= e) r --;
    a[l] = a[r];
    while (l < r && a[l] <= e) l ++;
    a[r] = a[l];
  }
  a[l] = e;
  return l;
}


// 应用：第k大数字  第k小数字

// 所谓“第（前）k大数问题”指的是在长度为n(n>=k)的乱序数组中S找出从大到小顺序的第（前）k个数的问题。
// 所谓“第（前）k小数问题”指的是在长度为n(n>=k)的乱序数组中S找出从小到大顺序的第（前）k个数的问题。

void notRecursion(int *a, int l, int r) {
  stack<int> st;
  st.push(l);
  st.push(r);
  while (!st.empty()) {
    int right = st.top();st.pop();
    int left  = st.top();st.pop();
    int p = partition1(a, left, right);
    // [left, p-1]   [p+1, right]
    if (left < p-1) {
      st.push(left);
      st.push(p-1);
    }
    if (p+1 < right) {
      st.push(p+1);
      st.push(right);
    }
  }
}


// a[l...lt] < e       a[gt...r] > e
// a[lt+1...i-1]==e

// a[i] == e; i++;
// a[i] < e  swap(a[lt+1], a[i]) lt++, i++;
// a[i] > e  swap(a[gt-1], a[i]) gt--; // 注意这一不用i++ 因为换回来的需要判断
// gt==i时 完成整个partition操作
// swap(a[l], a[lt])
// 对小于e 和 大于e的进行排序
// a[l...lt-1] a[gt...r]

void quickSort3Ways(int *a, int l, int r) {
  if (l >= r) return;
  swap(a[l], a[rand()%(r-l+1)+l]);
  int e = a[l];
  int lt = l; // a[l+1....lt] < e
  int gt = r+1; // a[gt...t] > e
  int i = l+1; // a[lt+1...i) == e

  while (i < gt) {
    if (a[i] < e) {
      swap(a[lt+1], a[i]);
      lt ++, i++;
    } else if (a[i] > e) {
      swap(a[i], a[gt-1]);
      gt --;
    } else if (a[i] == e){
      i ++;
    }
  }
  swap(a[l], a[lt]);
  quickSort3Ways(a, l, lt-1);
  quickSort3Ways(a, gt, r);
}


void quickSort(int *a, int n) {
  srand(time(NULL));
  quickSort3Ways(a, 0, n-1);
}

int main() {
  int a[] = {3,1,4,7,6,9,0,2,5,8};
  int n = sizeof(a)/sizeof(int);
  notRecursion(a, 0, n-1);
  for_each(a, a+n, [](int x) {cout << x << " ";});
  cout << endl;
  return 0;
}