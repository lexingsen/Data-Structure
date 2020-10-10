/*
 * @Description: 二叉树非递归中序遍历
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-10 14:34:39
 */
#include <bits/stdc++.h>
using namespace std;



struct node {
  int val;
  node *left, *right;
};

vector<int> inOrder(node *root) {
  vector<int> res;
  if (!root) return res;
  stack<node*> st;
  auto p = root;

  while (p || st.size()) {
    while (p) {
      st.push(p);
      p = p->left;
    }
    p = st.top();st.pop();
    res.push_back(p->val);
    p = p->right;
  }
  return res;
}


int main() {
  return 0;
}