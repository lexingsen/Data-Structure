#include <bits/stdc++.h>
using namespace std;

class LinkedCircleList {
private:
  struct node {
    int val;
    node *next;

    node() {}
    node(int x, node *next) {this->val = x;this->next = next;}


  };

  node *head;
  int size;
  
public:
  LinkedCircleList() {
    node *head = new node;
    head->next = head;
    size = 0;
  }
  ~LinkedCircleList() {
    while (head->next != head) delTail();
    delete head;
  }
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
  
  void insertHead(int x) {insert(0, x);}
  void insertTail(int x) {insert(size, x);}

  int del(int index) {
    if (index < 0 || index >= size) {
      cout << "the del index is invalid" << endl;
      return -1;
    }
    if (isEmpty()) {
      cout << "the LinkedCircleList is NULL" << endl;
      return -1;
    }
    node *p = head;
    for (int i=0; i<index; ++i) p = p->next;
    node *q = p->next;
    int res = q->val;
    p->next = q->next;
    delete q;
    size --;
    return res;
  }
  int delHead() {return del(0);}
  int delTail() {return del(size-1);}

  int search(int index) {
    if (index < 0 || index >= 0) {
      cout << "the search index is invalid" << endl;
      return -1;
    }
    if (isEmpty()) {
      cout << "the LinkedCircleList is NULL" << endl;
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
    while (p && p!=head) {
      cout << p->val << " ";
      p = p->next;
    }
    cout << endl;
  }
  bool isEmpty() {return head->next == head;}
  int getSize() {return size;}

};



int main() {
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  LinkedCircleList list = LinkedCircleList();
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