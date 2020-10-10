#include <bits/stdc++.h>
using namespace std;

class DoubleLinkedList {
private:
  struct node {
    int val;
    node *next, *prev;

    node() {}
    node(int x) {this->val = x;}
  };

  node *head;
  int size;
public:
  DoubleLinkedList() {
    head = new node();
    head->next = head->prev = NULL;
    size = 0;
  }
  ~DoubleLinkedList() {
    while (head->next && head->prev) delTail();
    delete head;
  }

  // [0, size]
  void insert(int index, int x) {
    if (index < 0 || index > size) {
      cout << "insert index is invalid" << endl;
      return ;
    }
    node *p = head;
    for (int i=0; i<index; ++i) p = p->next;
    node *q = new node(x);
    q->next = p->next;
    if (p->next) p->next->prev = q;
    q->prev = p;
    p->next = q;
    size ++;
  }
  void insertHead(int x) {insert(0, x);}
  void insertTail(int x) {insert(size, x);}
  int del(int index) {
    if (index < 0 || index >= size) {
      cout << "the index is invalid" << endl;
      return -1;
    }
    if (!head->next && !head->prev) {
      cout << "the DoubleLinkedList is null" << endl;
      return -1;
    }
    node *p = head;
    for (int i=0; i<index; ++i) p = p->next;
    node *q = p->next;
    int res = q->val;

    // 判断待删除的节点是不是最后一个节点
    if (q->next) {
      q->next->prev = p;
      p->next = q->next;
      delete q;
      q = NULL;
    } else {
      p->next = NULL;
      delete q;
      q = NULL;
    }
    size --;
    return res;
  }
  int delHead() {return del(0);}
  int delTail() {return del(size-1);}
  int search(int index) {
    if (index < 0 || index >= size) {
      cout << "the search index  invalid" << endl;
      return -1;
    }

    if (!head->next && !head->prev) {
      cout << "the DoubleLinkedList is NULL" << endl;
      return -1;
    }
    node *p = head->next;
    for (int i=0; i<index; ++i) p = p->next;
    return p->val;
  }
  int searchHead() {return search(0);}
  int searchTail() {return search(size-1);}

  void show() {
    node *p = head->next;
    while (p) {
      cout << p->val << " ";
      p = p->next;
    }
    cout << endl;
  }

  bool isEmpty() {return !head->next && !head->prev;}
};

int main() {
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  DoubleLinkedList list = DoubleLinkedList();
  for (int i=0; i<n; ++i) list.insertTail(a[i]);
  list.show();
  list.delHead();
  list.show();
  list.delTail();
  list.show();
  list.del(2);
  list.show();
  cout << list.searchHead() << endl;
  cout << list.searchTail() << endl;
  cout << list.search(2) << endl;
  cout << list.search(0) << endl;
  cout << list.search(1) << endl;
  return 0;
}