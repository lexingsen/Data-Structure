#include <bits/stdc++.h>
using namespace std;


// min max floor ceil rank select
template <typename K, typename V>
class BST {
private:
  struct node {
    K key;
    V value;
    node *left, *right;
  
    node (K k, V v) {
      this->key = k;
      this->value = v;
      this->left = this->right = nullptr;
    }

    node (node *x) {
      this->key = x->key;
      this->value = x->value;
      this->left = x->left;
      this->right = x->right;
    }
  };

  node* insert(node *root, K key, V value) {
    if (!root) {
      size ++;
      return new node(key, value);
    }
    if (key == root->key) {
      root->key = key;
    } else if (key < root->key) {
      root->left = insert(root->left, key, value);
    } else {
      root->right = insert(root->right, key, value);
    }
  }

  V* search(node *root, K key) {
    if (!root) return nullptr;
    if (root->key == key) {
      return &(root->value);
    } else if (root->key < key) {
      return search(root->left, key);
    } else {
      return search(root->right, key);
    }
  }


  bool contain(node *root, K key) {
    if (!root) return false;
    if (key == root->key) return true;
    else if (key < root->key) return contain(root->left, key);
    else return contain(root->right, key);
  }

  node *minimum(node *root) {
    if (!root->left) return root;
    return minimum(root->left);
  }

  node *maximum(node *root) {
    if (!root->right) return root;
    return maximum(root->right);
  }


  node *removeMin(node *root) {
    if (!root->left) {
      node *right = root->right;
      delete root;
      size --;
      return right;
    } 
    root->left = removeMin(root->left);
    return root;
  }

  node *removeMax(node *root) {
    if (!root->right) {
      node *left = root->left;
      delete root;
      size --;
      return left;
    }
    root->right = removeMax(root->right);
    return root;
  }


  node* remove(node *root, K key) {
    if (!root) {
      return nullptr;
    } 
    if (key < root->key) {
      root->left = remove(root->left, key);
      return root;
    } else if (key > root->key) {
      root->right = remove(root->right, key);
      return root;
    } else {
      if (!root->left) {
        node *right = root->right;
        delete root;
        size --;
        return right;
      }
      if (!root->right) {
        node *left = root->left;
        delete root;
        size --;
        return left;
      } 
      // node->left!=nullptr node->right!=nullptr
      node *d = root;
      node *s = new node(minimum(root->right));
      size ++;
      s->right = removeMin(root->right);
      s->left = d->left;
      delete d;
      size --;
      d = nullptr;
      return s;
    }
  }

  node *root;
  int size;
public:
  BST() {
    root = nullptr;
    size = 0;
  }

  ~BST() {
    destroy(root);
  }

  void insert(K key, V value) {
    root = insert(root, key, value);
  }

  V* search(K key) {
    return search(root, key);
  }


  // 删除任意节点  左子树的最大值  右子树的最小值
  void remove(K key) {
    root = remove(root, key);
  }

  bool contain(K key) {
    return contian(root, key);
  }




  int getSize() {return size;}
  bool isEmpty() {return root==nullptr;}

  K minimum() {
    assert(size != 0);
    node *x = minimum(root);
    return x->key;
  }

  K maximum() {
    assert(size != 0);
    node *x = maximum(root);
    return x->key;
  }

  void removeMin() {
    if (root) {
      root = removeMin(root);
    }
  }


  void removeMax() {
    if (root) {
      root = removeMax(root);
    }
  }


  void destroy(node* root){
    if(root) {
      destroy(root->left);
      destroy(root->right);
      delete root;
      size --;
    }
  }


  void bfs() {
    if (!root) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
      node *f = q.front();q.pop();
      cout << f->value << " ";
      if (f->left) q.push(f->left);
      if (f->right) q.push(f->right);
    }
  }
};


int main() {
  BST<int,int> bst;
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  for (int i=0; i<n; ++i) bst.insert(i,a[i]);

  bst.bfs();

  return 0;
}