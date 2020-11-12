/*
 * @Description: 中序和后序序列重建二叉树
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-10 17:45:27
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
    unordered_map<int, int> pos;
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
      int n = in.size();
      for (int i=0; i<n; ++i) pos[in[i]] = i;
      return dfs(in, post, 0, n-1, 0, n-1);
    }
    
    TreeNode* dfs(vector<int> &in, vector<int> &post, int inL, int inR, int postL, int postR) {
      if (postL > postR) return nullptr;
      int val = post[postR];
      int k = pos[val];
      int rightLen = inR - k;

      auto root = new TreeNode(val);
      root->left  = dfs(in, post, inL, k-1, postL,postR-rightLen-1);
      root->right = dfs(in, post, k+1, inR, postR-rightLen, postR-1);
      return root;
    }
};

int main() {
  return 0;
}