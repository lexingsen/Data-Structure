/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-11-06 09:33:54
 */
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
  TreeNode *left, *right;
  int val;
};

bool isSameTree(TreeNode* p, TreeNode *q) {
  if (!p && !q) return true;
  if ((p && !q) || (q && !p)) return false;
  if (p->val == q->val) {
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  } else {
    return false;
  }
}