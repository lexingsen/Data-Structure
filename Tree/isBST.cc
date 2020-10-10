#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left, *right;
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
      if (!root) return true;
      TreeNode *left = root->left;
      TreeNode *right = root->right;
      while (left) {
        if (root->val  <= left->val) return false;
        left = left->right;
      }
      while (right) {
        if (root->val >= right->val) return false;
        right = right->left;
      }
      return isValidBST(root->left) && isValidBST(root->right);
    }
};