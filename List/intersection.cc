/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-11-06 12:07:38
 */
#include <forward_list>
#include <bits/stdc++.h>
using namespace std;


int main() {
  forward_list<int> a{1,2,3,4,5,6,7,8,9};
  forward_list<int> b{1,2,5,7,9};
  forward_list<int> c;
  auto i=a.begin(),j=b.begin();
  while (i != a.end() && j != b.end()) {
    if (*i == *j) {
      c.push_front(*i);
      i ++,j++;
    } else {
      *i > *j?j++:i++;
    }
  }
  if (c.empty()) {
    cout << "no" << endl;
  } else {
    for_each(c.begin(), c.end(), [](int x) {cout << x << " ";});
  }
  return 0;
}