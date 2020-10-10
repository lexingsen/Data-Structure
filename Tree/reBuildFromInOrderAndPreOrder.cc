/*
 * @Description: 先序和中序序列重建二叉树
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-10 16:54:03
 */
#include <bits/stdc++.h>
using namespace std;



struct node {
  int val;
  node *left, *right;

  node (int x):val(x),right(nullptr),left(nullptr) {}
};

// 存储中序遍历序列每个元素及其对应的下标   空间换时间  每个元素在中序序列的下标O(1)就可以查找到
unordered_map<int, int> pos;

node *dfs(vector<int> &pre, vector<int> &in, int preL, int preR, int inL, int inR) {
  if (preL > preR) return nullptr;
  int val = pre[preL]; // 当前树根节点的值
  int k = pos[val]; // k是中序序列中根节点所在的下标
  int leftLen = k-inL;
  node *root = new node(val);
  root->left = dfs(pre, in, preL+1, preL+leftLen, inL, k-1);
  root->right = dfs(pre, in, preL+leftLen+1, preR, k+1, inR);
  return root;
}


node* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int n = preorder.size(); 
  for (int i=0; i<n; ++i) pos[inorder[i]] = i;
  return dfs(preorder, inorder, 0, n-1, 0, n-1);
}

