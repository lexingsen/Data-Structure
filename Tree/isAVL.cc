#include <bits/stdc++.h>
using namespace std;


struct node {
  int val;
  node *left, *right;
};

int height(node *root) {
  if (!root) return 0;
  else {
    int l = height(root->left);
    int r = height(root->right);
    return max(l,r) + 1;
  }
}

bool isAVL(node *root) {
  if (!root) 
    return true;
  if (abs(height(root->left)-height(root->right)) > 1) 
    return false;
  else
    return isAVL(root->left) && isAVL(root->right);
}

int main() {
  return 0;
}