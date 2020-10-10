#include <bits/stdc++.h>
#include "printTree.h"
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
    return max(l,r)+1;
  }
}

int size(node *root) {
  if (!root) return 0;
  else return size(root->left)+size(root->right)+1;
}



bool isFBT(node *root) {
  if (!root) return true;
  else return size(root)==pow(2,height(root))-1;
}

int main() {
  return 0;
}