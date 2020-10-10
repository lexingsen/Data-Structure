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
  node *cur = root;
  while (cur || !st.empty()) {
    while (cur) {
      res.push_back(cur->val);
      st.push(cur);
      cur = cur->right;
    }

    node *top = st.top();st.pop();
    cur = top->right;
  }
}

int main() {
  return 0;
}