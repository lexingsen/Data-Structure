/*
 * @Description: 三元组的实现
 * @Language: 
 * @Author: 
 * @Date: 2020-11-11 11:03:06
 */
#include <bits/stdc++.h>
using namespace std;

class TripleNode {
public:
  int row;
  int col;
  int val;

  TripleNode(int row, int col, int val):
    row(row), col(col), val(val) {}

  TripleNode() {
    this->row = this->col = this->val = 0;
  }  
};


class SparseMatrix{
private:
  TripleNode* data;
  int row;
  int col;
  int cnt;//非零元素的个数  

public:
  SparseMatrix(int size) {
    data = new TripleNode[size];  
    this->row = this->col = this->cnt = 0;
  }

  ~SparseMatrix() {
    delete[] data;
  }

  SparseMatrix(vector<vector<int>> &a) {
    int n = a.size();
    int m = a[0].size();
    this->row = n;
    this->col = m;
    for (int i=0; i<n; ++i) {
      for (int j=0; j<m; ++j) {
        if (a[i][j] != 0) cnt ++;
      }
    }
    data = new TripleNode[cnt];
    int k=0;
    for (int i=0; i<n; ++i) {
      for (int j=0; j<m; ++j) {
        if (a[i][j] != 0) {
          data[k ++] = TripleNode(i,j,a[i][j]);
        }
      }
    }
  }

  void show() {
    cout << "row:" << row << endl;
    cout << "col:" << col << endl; 
    cout << "row    col    val" << endl;
    for (int i=0; i<row; ++i) {
      cout << data[i].row << "       " << data[i].col << "       " << data[i].val << endl;
    }
  }
};

int main() {
  vector<vector<int>> a = {
    {1,0,0,0,0},
    {0,2,0,0,0},
    {0,0,3,0,0},
    {0,0,0,4,0},
    {0,0,0,0,5}
  };
  SparseMatrix s(a);
  s.show();
  return 0;
}