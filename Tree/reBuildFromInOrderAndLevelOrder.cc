/*
 * @Description: 根据层序和中序遍历序列构造二叉树
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-13 19:14:07
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;

  TreeNode(int val):val(val) {
    this->left = this->right = nullptr;
  }
};

/*
层序遍历第一个必定是根节点


*/

TreeNode *build(vector<int> level, vector<int> in, int left, int right) {
  if (!level.size()) return nullptr;
  int val = level[0];
  TreeNode *root = new TreeNode(val);
  int k;
  // 寻找根节点子在中序序列中的下标 可以使用hashmap优化时间复杂度为O(1)
  for (int i=left; i<=right; ++i) {
    if (val == in[i]) {
      k = i;
      break;
    }
  }
  
}





int main() {

}

