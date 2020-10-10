#include "LinkedList.h"

// 链式栈不需要判断满
class LinkedStack {
private:
  LinkedList st;
public:
  LinkedStack() {
    st = LinkedList();
  }
  ~LinkedStack() {
    
  }

  bool isEmpty() {return st.getSize()==0;}

  int pop() {
    return st.delHead();
  }

  void push(int x) {
    st.insertHead(x);
  }

  int top() {
    return st.searchHead();
  }
};

int main() {
  LinkedStack stack = LinkedStack();
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  for (int i=0; i<n; ++i) stack.push(a[i]);
  while (!stack.isEmpty()) {
    cout << stack.top() << " ";
    stack.pop();
  }
  cout << endl;
  return 0;
}