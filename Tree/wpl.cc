/*
 * @Description: 带权最短路径WPL的求解
 * @Language: 
 * @Author: 
 * @Date: 2020-10-24 22:27:10
 */
#include <bits/stdc++.h>
using namespace std;


struct node {
  int val;
  node *left, *right;
};


int sum = 0;

void wpl(node *root, int depth) {
  if (!root->left && !root->right) {
    sum += (root->val) * depth;
  } 
  else if (!root->left) {
    wpl(root->right, depth+1);
  } else if (!root->right) {
    wpl(root->left, depth+1);
  }
}

void wpl(node *root) {
  wpl(root, 0);
}




int main() {
  priority_queue<int, vector<int>, greater<int>> pq;
  int a[] = {2,3,6,9,14,15,16,17};
  int n = sizeof(a)/sizeof(int);
  for (int i=0; i<n; ++i) pq.push(a[i]);
  int res = 0;
  while (pq.size() > 1) {
    int a = pq.top();pq.pop();
    int b = pq.top();pq.pop();
    res += (a+b);
    pq.push(a+b);
  }
  cout << res << endl;
  return 0;
}