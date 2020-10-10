#include <bits/stdc++.h>
using namespace std;


struct node {
  int val;
  node *left, *right;
};


bool isCBT(node *root) {
  if (!root) return true;
  queue<node*> q;
  q.push(root);
  while (!q.empty()) {
    node *front = q.front();q.pop();
    if (front) {
      q.push(front->left);
      q.push(front->right);
    } else {
      while (!q.empty()) {
        front = q.front();q.pop();
        if (front) return false;
      }
    }
  }
  return true;
}

int main() {
  return 0;
}