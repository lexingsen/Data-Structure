/*
 * @Description: 二叉树非递归后序遍历
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-10 14:35:19
 */
#include <bits/stdc++.h>
using namespace std;

struct node {
  int val;
  node *left, *right;
};



vector<int> postOrder(node *root) {
  vector<int> res;
  if (!root) return res;
  stack<node*> st;
  auto p = root;
  node* tag = nullptr;
  while (p || st.size()) {
    while (p) {
      st.push(p);
      p = p->left;
    }
    p = st.top();st.pop();
    if (!p->right || p->right==tag) {
      res.push_back(p->val);
      tag = p;
      p = nullptr;
    } else {
      st.push(p);
      p = p->right;
    }
  }
  return res;
}


int main() {
  return 0;
}