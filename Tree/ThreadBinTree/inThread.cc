/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-13 19:31:50
 */
#include <bits/stdc++.h>
using namespace std;


struct node {
  int val;
  node *left, *right;
  bool ltag, rtag;
};


void inThread(node *root, node *pre) {
  if (root) {
    inThread(root->left, pre);
    if (root->left==nullptr) {
      root->left = pre;
      root->ltag = 1;
    }
    if (pre && pre->right==nullptr) {
      pre->right = root;
      pre->rtag = 1;
    }
    pre = root;
    inThread(root->right, pre);
  }
}

node *firstNode(node *root) {
  while (root->ltag==0) root = root->left;
  return root;
}


// 中序线索二叉树中节点p在中序序列中的后继
node *nextNode(node *root) {
  if(root->rtag==0) return firstNode(root->right);
  else return root->right;
}

void inOrder(node *root) {
  for (node *p=firstNode(root); p; p=nextNode(p)) {
    cout << p->val << " ";
  }
}

