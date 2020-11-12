/*
 * @Description: 最近公共祖先
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-10 21:20:01
 */

/*
递归
tarjian  离线
倍增   在线
ST表   在线
RMQ  

*/
#include <bits/stdc++.h>
using namespace std;


struct node {
  int val;
  node *left, *right;
};




node* lca(node *root, node *p, node *q) {

  if (!root || root==p || root==q) return root;
  auto left = lca(root->left, p, q); // left!=null
  auto right = lca(root->right, p, q); // right!=null


  if (!left) return right;
  if (!right) return left;
  // left!=nullptr && right!=nullptr
  return root;
}


