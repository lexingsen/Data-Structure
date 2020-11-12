/*
 * @Description: bfs求解树的深度
 * @Language: 
 * @Author: 
 * @Date: 2020-11-09 21:06:05
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
};


void dfsGetDepth(TreeNode *root, int &x) {
  if (!root) return;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    for (int i=0; i<n; ++i) {
      auto f=q.front();q.pop();
      if (f->left) q.push(f->left);
      if (f->right) q.push(f->right);
    }
    x ++;
  }
}

int main() {
  return 0;
}