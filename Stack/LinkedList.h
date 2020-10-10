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
  int del(int index) {
    if (size<0 || index>=size) {
      cout << "the index is invalid" << endl;
      return -1;
    }

    if (isEmpty()) {
      cout << "the LinkedList is null!" << endl;
      return -1;
    }

    node *p = head;
    for (int i=0; i<index; ++i) p = p->next;
    node *q = p->next;
    int res = q->val;
    p->next = q->next;
    delete q;
    q = NULL;
    size --;
    return res;
  }

  int delHead() {
    return del(0);
  }

  int delTail() {
    return del(size-1);
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