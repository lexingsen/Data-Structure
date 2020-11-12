/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-11-06 13:06:54
 */
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
  TreeNode *left, *right;
  int val;
};


bool isSimilarTree(TreeNode *a, TreeNode *b) {
  if (!a && !b) return false;
  else if ((!a && b) || (!b && a)) return false;
  else {
    return isSimilarTree(a->left, b->left) && isSimilarTree(a->right, b->right);
  }
}