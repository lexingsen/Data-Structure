/*
 * @Description: 多机调度问题
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-26 07:41:18
 */
#include <bits/stdc++.h>
using namespace std;

const int N=10010;
int speed[N];// 作业花费时间
int mintime[N]; // 存放 作业完成的时间


bool cmp(const int& x, const int& y) {return x>y;}

int main() {
  freopen("in.txt", "r", stdin);
  int n,m;
  cin >> n >> m; // 默认n>m;n<=m不需要调度处理
  memset(speed, 0, sizeof(speed));
  memset(mintime, 0, sizeof(mintime));

  int res = 0;
  for (int i=0; i<n; ++i) cin >> speed[i]; // 输入n个作业所需要的处理时间
  sort(speed, speed+n, cmp);
  for (int i=0; i<n; ++i) {
    res += (res+(*min_element(mintime, mintime+m)));
    *min_element(mintime, mintime+m)+=speed[i];
  }

  cout << res << endl;
  cout << *max_element(mintime, mintime+m) << endl;
  return 0;
}