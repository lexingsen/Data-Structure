/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-10 16:39:07
 */
/*
 * @Description: 判断一棵树是否为对称二叉树 LeetCode.101
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-10 16:39:07
 */
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool dfs(TreeNode* p, TreeNode *q) {
      if (!p && !q) return true;
      if ((!p&&q) || (!q&&p)) return false;
      return (p->val==q->val && dfs(p->left, q->right) && dfs(p->right, q->left));
    }
    bool isSymmetric(TreeNode* root) {
      return dfs(root, root);
    }
};