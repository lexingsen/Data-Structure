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
  while (p || !st.empty()) {
    if (p) {
      res.push_back(p->val);
      st.push(p);
      p = p->left;
    } else {
      p = st.top();
      if (p->right && p->right!=tag) {

      } else {
        st.pop();
        res.push_back(p->val);
        tag = p;
        p = nullptr;
      }
    }
  }
}


int main() {
  return 0;
}