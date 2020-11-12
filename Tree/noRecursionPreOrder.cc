/*
 * @Description: 二叉树非递归先序遍历
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-10 14:34:53
 */
#include <bits/stdc++.h>
using namespace std;


struct node {
  int val;
  node *left, *right;
};

vector<int> preOrder(node *root) {
  vector<int> res;
  if (!root) return res;
  stack<node*> st;
  auto p = root;
  stack<node*> st;
  while (p || st.size()) {
    if (p) {
      res.push_back(p->val);
      st.push(p);
      p = p->left;
    } else {
      auto top = st.top();st.pop();
      p = top->right;
    }
  }
  return res;
}

int main() {
  return 0;
}