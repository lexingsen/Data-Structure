#include <cmath>  
#include <iostream>  
#include <vector>  
using std::vector;  
using std::cout;  
using std::endl;  
using std::max;  

void PrintBinaryTree(TreeNode *root);  

struct TreeNode  
{  
  TreeNode *left;  
  TreeNode *right;  
  int val;  
  TreeNode(int x=0)  
   : val(x), left(NULL), right(NULL){}  
};  

