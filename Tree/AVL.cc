/*
 * @Description: AVL树C++实现
 * @Language: C++
 * @Author: lexingsen
 * @Date: 2020-10-09 15:25:29
 */


#include <bits/stdc++.h>
using namespace std;



class AVL {
private:
  struct TreeNode {
    int val;
    int height;
    TreeNode *left, *right; 

    TreeNode (int x) {
      this->val = x;
      this->height = 1;
      this->left = this->right = nullptr;
    }

    TreeNode (TreeNode *x) {
      this->val = x->val;
      this->left = x->left;
      this->right = x->right;
      this->height = x->height;
    } 
  };


  TreeNode *root;
  int size;

  void updateHeight(TreeNode *root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
  }

  int getHeight(TreeNode *root) {
    return !root?0:root->height;
  }

  int getBalanceFactor(TreeNode* root) {
    return !root?0:(getHeight(root->left) - getHeight(root->right));
  }

  TreeNode* add(TreeNode *root, int x) {
    if (!root) {
      size ++;
      return new TreeNode(x);
    }

    if (x < root->val) {
      root->left = add(root->left, x);
    } else if (x > root->val) {
      root->right = add(root->right, x);
    } else {
      root->val = x;
    }


    // 更新高度
    updateHeight(root);

    int balanceFactor = getBalanceFactor(root);
    // 维护平衡
    // LL
    if (balanceFactor==2 && getBalanceFactor(root->left)>=0) {
      return rightRotate(root);
    }
    // LR
    //                 y
    //                / \
    //               x   t4
    //              / \        leftRotate(x)   rightRotate(y)
    //             t1  z
    //                / \
    //               t2 t3
    if (balanceFactor==2 && getBalanceFactor(root->left)<0) {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
    // RR
    if (balanceFactor==-2 && getBalanceFactor(root->right)<=0) {
      return leftRotate(root);
    }
    // RL
    //                y
    //               / \
    //              t1  x 
    //                 / \       rightRotate(x)  leftRotate(y)
    //                z   t4 
    //               / \   
    //              t2  t3
    if (balanceFactor==-2 && getBalanceFactor(root->right)>0) {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
    return root;
  }

public:
  AVL() {
    this->root = nullptr;
    this->size = 0;
    this->i = 0;
  }


  ~AVL() {
    destroy(root);
  }


  // 对节点y进行向左旋转操作，返回旋转后新的根节点x
  //    y                             x
  //  /  \                          /   \
  // T1   x      向左旋转 (y)       y     z
  //     / \   - - - - - - - ->   / \   / \
  //   T2   z                    T1 T2 T3 T4
  //       / \
  //      T3 T4
  TreeNode* leftRotate(TreeNode *y) {
    TreeNode *x = y->right;
    TreeNode *t2 = x->left;
    x->left = y;
    y->right = t2;
    updateHeight(y);
    updateHeight(x);
    return x;
  }

  // 对节点y进行向右旋转操作，返回旋转后新的根节点x
  //        y                              x
  //       / \                           /   \
  //      x   T4     向右旋转 (y)        z     y
  //     / \       - - - - - - - ->    / \   / \
  //    z   T3                       T1  T2 T3 T4
  //   / \
  // T1   T2
  TreeNode* rightRotate(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *t3 = x->right;
    x->right = y;
    y->left = t3;
    updateHeight(y);
    updateHeight(x);
    return x;
  }

  void add(int x) {
    root = add(root, x);
  }


  void destroy(TreeNode *root) {
    if (root) {
      destroy(root->left);
      destroy(root->right);
      delete root;
    }
  }

  void bfs() {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *f = q.front();q.pop();
      cout << f->val << " ";
      if (f->left) q.push(f->left);
      if (f->right) q.push(f->right);
    }
    cout << endl;
  }

  bool isBST() {
    // 判断中序遍历序列
    vector<int> res;
    inOrder(root, res);
    for (int i=1; i<res.size(); ++i) {
      if (res[i-1] >= res[i]) return false;
    }
    return true;
  }

  bool isBalanced() {
    return isBalanced(root);
  }

  bool isBalanced(TreeNode *root) {
    if (!root) return 1;
    if (abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
  }


  void inOrder(TreeNode *root, vector<int> &res) {
    if (root) {
      inOrder(root->left, res);
      res.push_back(root->val);
      inOrder(root->right, res);
    }
  }

  TreeNode *getTreeNode(int x) {
    return getTreeNode(root, x);
  }

  TreeNode *getTreeNode(TreeNode *root, int x) {
    if (!root) return nullptr;
    if (x == root->val) {
      return root;
    } else if (x < root->val) {
      return getTreeNode(root->left, x);
    } else {
      return getTreeNode(root->right, x);
    }
  }
  bool remove(int x) {
    TreeNode *res = getTreeNode(x);
    if (!res) return false;
    else {
      root = remove(root, x);
      return true;
    }
  }

  TreeNode *remove(TreeNode *root, int x) {
    if (!root) return nullptr;

    TreeNode *res;
    if (x < root->val) {
      root->left = remove(root->left, x);
      res = root;
    } else if (x > root->val) {
      root->right = remove(root->right, x);
      res = root;
    } else {
      // root->val == x
      if (!root->left) {
        TreeNode *right = root->right;
        delete root;
        size --;
        res = right;
      } else if (!root->right) {
        TreeNode *left = root->left;
        delete root;
        size --;
        res = left;
      } else {
        TreeNode *s = new TreeNode(maximum(root->left));
        size ++;
        s->left = removeMin(root->left);
        s->right = root->right;
        delete root;
        res = s;
      }

    }
    if (!res) return nullptr;
    updateHeight(res);
    int balanceFactor = getBalanceFactor(res);
    if (balanceFactor==2 && getBalanceFactor(res->left)>=0) {
      return rightRotate(res);
    }
    if (balanceFactor==2 && getBalanceFactor(res->left)<0) {
      res->left = leftRotate(res->left);
      return rightRotate(res);
    }
    if (balanceFactor==-2 && getBalanceFactor(res->right)<=0) {
      return leftRotate(res);
    }
    if (balanceFactor==-2 && getBalanceFactor(res->right)>0) {
      res->right = rightRotate(res->right);
      return leftRotate(res);
    }
    return res;
  }

  TreeNode* removeMin(TreeNode *root) {
    if (!root->left) {
      TreeNode *right = root->right;
      delete root;
      size --;
      return right;
    } else {
      root->left = removeMin(root->left);
      return root;
    }
  }

  TreeNode *removeMax(TreeNode *root) {
    if (!root->right) {
      TreeNode *left = root->left;
      delete root;
      size --;
      return left;
    } else {
      root->right = removeMax(root->right);
      return root;
    }
  }

  TreeNode *minimum(TreeNode *root) {
    if (!root->left) return root;
    else return minimum(root->left);
  }

  TreeNode *maximum(TreeNode *root) {
    if (!root->right) return root;
    else return maximum(root->right);
  }

  void show() {
    PrintBinaryTree(root);
  }


  static int MaxLevel(TreeNode *root) {  
    if(root == NULL) return 0;  
    return max(MaxLevel(root->left), MaxLevel(root->right)) + 1;  
  }  

  static bool IsAllElementsNULL(const vector<TreeNode*> &nodes) {  
    vector<TreeNode*>::const_iterator it = nodes.begin();  

    while(it != nodes.end()){  
      if(*it) return false;   
      ++it;  
    }  
    return true;  
  }  

  static void PrintWhiteSpaces(int num) {  
    for(int i=0; i<num; ++i)  
      cout << " ";  
  }  

  void PrintNode(vector<TreeNode*> &nodes, int level, int max_level) {  
    if(nodes.empty() || IsAllElementsNULL(nodes)) return; // exit  

    int floor = max_level - level;  
    int endge_lines = 1 << (max(floor-1, 0));  
    int first_spaces = (1 << floor) - 1;  
    int between_spaces = (1 << (floor+1)) - 1;  

    PrintWhiteSpaces(first_spaces);  

    // print the 'level' level   
    vector<TreeNode*> new_nodes;  
    vector<TreeNode*>::const_iterator it = nodes.begin();  
    for(; it != nodes.end(); ++it){  
      if(*it != NULL){  
        cout << (*it)->val;  
        new_nodes.push_back((*it)->left);  
        new_nodes.push_back((*it)->right);  
      }  
      else{  
        new_nodes.push_back(NULL);  
        new_nodes.push_back(NULL);  
        cout << " ";  
      }  
      PrintWhiteSpaces(between_spaces);  
    }  
    cout << endl;  

    // print the following /s and \s  
    for(int i=1; i<= endge_lines; ++i){  
      for(int j=0; j<nodes.size(); ++j){  
        PrintWhiteSpaces(first_spaces - i);  
        if(nodes[j] == NULL){  
          PrintWhiteSpaces(endge_lines + endge_lines + i + 1);  
          continue;  
        }  
        if(nodes[j]->left != NULL)  
          cout << "/";  
        else  
          PrintWhiteSpaces(1);  

        PrintWhiteSpaces(i+i-1);  

        if(nodes[j]->right != NULL)  
          cout << "\\";  
        else  
          PrintWhiteSpaces(1);  

        PrintWhiteSpaces(endge_lines + endge_lines - i);  
      }  
      cout << endl;  
    }  

    PrintNode(new_nodes, level+1, max_level);  
  }  

  void PrintBinaryTree(TreeNode *root) {  
    int max_level = MaxLevel(root);  
    vector<TreeNode*> nodes;  

    nodes.push_back(root);  

    PrintNode(nodes, 1, max_level);  
  }  


  void zigzag() {
    zigzag(root);
  }

  void zigzag(TreeNode *root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      auto f = q.front();q.pop();
      cout << f->val << " ";
      if (f->right) q.push(f->right);
      if (f->left) q.push(f->left);
    }
    cout << endl;
  }

  int noRecursionGetHeight() {
    return noRecursionGetHeight(root);
  }

  int noRecursionGetHeight(TreeNode *root) {
    // 利用层序遍历
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
      height ++;
      int size = q.size();
      int cnt = 0;
      while (cnt < size) {
        auto f = q.front();q.pop();
        cnt ++;
        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);
      }
    }
    return height;
  }

  int preOrderKth(int k) {
    return preOrderKth(root, k);
  }

  int width() {
    return width(root);
  }



private:
  int width(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int w = 1;
    while (!q.empty()) {
      int size = q.size();
      while (size > 0) {
        auto f = q.front();q.pop();
        size --;
        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);

      }
      w = max(w, (int)q.size());
    }
    return w;
  }


  
  int i;
  int preOrderKth(TreeNode *root, int &k) {
    if (!root) return -1;
    if (k == i) return root->val;
    i ++;
    int left = preOrderKth(root->left, k);
    if (left != -1) return left;
    int right = preOrderKth(root->right, k);
    if (right != -1) return right;
  }

};


int main() {
  int a[] = {24,13,53,37,90,48};
  int n = sizeof(a)/sizeof(int);
  AVL avl;
  int x;
  cout << "input:";
  cin >> x;
  for (int i=1; i<=x; ++i) avl.add(i);
  avl.show();
  avl.zigzag();
  avl.bfs();

  cout << "height:" << avl.noRecursionGetHeight() << endl;
  cout << "width:" << avl.width() << endl;
  return 0;
}