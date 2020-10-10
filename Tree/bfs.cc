/*
 * @Description: 二叉树层序遍历
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-10 16:10:46
 */
#include <bits/stdc++.h>
using namespace std;

struct node {
  int val;
  node *left, *right;
};


void bfs(node *root) {
  if (!root) return;
  queue<node*> q;
  q.push(root);
  while (!q.empty()) {
    auto f = q.front();q.pop();
    cout << f->val << " ";
    if (f->left) q.push(f->left);
    if (f->right) q.push(f->right);
  }
  cout << endl;
}


int main() {
  return 0;
}