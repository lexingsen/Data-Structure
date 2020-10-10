#include <bits/stdc++.h>
using namespace std;

class DoubleLinkedCircleList{
private:
  struct node {
    int val;
    node *next, *prev;

    node (int x) {this->val = x;}
    node () {}
  };

  node *head;
  int size;
public:
  DoubleLinkedCircleList() {
    head = new node();
    head->next = head->prev = head;
    size = 0;
  }
  ~DoubleLinkedCircleList() {
    while (head->next!=head && head->prev!=head) delTail();
    delete head;
  }

  void insert(int index, int x) {
    if (index<0 || index>size) {
			cout << "the index is invalid!" << endl;
			return;
		} 


    // p是待删除节点的前去节点
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
    if (index<0 || index>=size) {
			cout << "the index is invalid!" << endl;
			return -1;
		}
	
		if (isEmpty()) {
			cout << "the DoubleLinkedCircleList is null!" << endl;
			return -1;
		} 

    node *p = head;
    for (int i=0; i<index; ++i) p = p->next;
    node *q = p->next;
    int res = q->val;
    q->next->prev = p;
    p->next = q->next;
    delete q;
    q = NULL;
    size --;
  }

  int delHead() {return del(0);}
  int delTail() {return del(size-1);}

  int search(int index) {
    if (index<0 || index>=size) {
			cout << "the index is invalid!" << endl;
			return -1;
		}
		
		if (head->next == head && head->prev == head) {
			cout << "the DoubleLinkedCircleList is null!" << endl;
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
  bool isEmpty() {return head->next==head && head->prev==head;}
  int getSize() {return size;}
};

int main() {
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  DoubleLinkedCircleList list = DoubleLinkedCircleList();
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