#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class LinkedList {
private:
  struct node {
    int val;
    node *next;


    node() {}
    node(int x, node *next) {
      this->val = x;
      this->next = next;
    }
  };


  node *head;
  int size;
public:
  LinkedList() {
    head = new node;
    head->next = NULL;
    size = 0;
  }
  ~LinkedList() {
    while (head->next) delTail();
    delete head;
  }
  bool isEmpty() {return size==0;}
  int getSize() {return size;}

  // [0,size]

  void insert(int index, int x) {
    if (index < 0 || index > size) {
      cout << "the index is invalid!" << endl;
      return;
    }
    node *p = head;
    for (int i=0; i<index; ++i) p = p->next;
    node *q = new node(x, p->next);
    p->next = q;
    size ++;
  }

  void insertTail(int x) {
    insert(size, x);
  }


  void insertHead(int x) {
    insert(0, x);
  }

  // [0, size-1]
  void del(int index) {
    if (size<0 || index>=size) {
      cout << "the index is invalid" << endl;
      return;
    }

    if (isEmpty()) {
      cout << "the LinkedList is null!" << endl;
      return;
    }

    node *p = head;
    for (int i=0; i<index; ++i) p = p->next;
    node *q = p->next;
    p->next = q->next;
    delete q;
    q = NULL;
    size --;
  }

  void delHead() {
    del(0);
  }

  void delTail() {
    del(size-1);
  }


  // index [0,size-1]
  int search(int index) {
    if (index < 0 || index >= size) {
      cout << "the index is invalid" << endl;
      return -1;
    }
    if (isEmpty()) {
      cout << "the LinkedList is empty" << endl;
      return -1;
    }

    node *p = head->next;
    for (int i=0; i<index; ++i) p = p->next;
    return p->val;
  } 

  int searchHead() {
    return search(0);
  }


  int searchTail() {
    return search(size-1);
  }

  void show() {
    node *p = head->next;
    while (p) {
      cout << p->val << " ";
      p = p->next;
    }
    cout << endl;
  }
};



int main() {
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  LinkedList list = LinkedList();
  cout << "xxxxxxxxxxxxxxxxxxxxx" << endl;
  for (int i=0; i<n; ++i) list.insertTail(a[i]);
  list.show();
  list.delHead();
  list.show();
  cout << "size:" << list.getSize() << endl;
  list.delTail();
  list.show();
  list.del(2);
  list.show();
  cout << list.searchHead() << endl;
  cout << list.searchTail() << endl;
  cout << "======================" << endl;
  cout << list.search(2) << endl;
  cout << list.search(0) << endl;
  cout << "======================" << endl;
  cout << list.search(1) << endl;
  list.show();
  return 0;
}