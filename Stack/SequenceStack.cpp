#include <bits/stdc++.h>
using namespace std;

const int maxsize=100;
class SequenceStack {
private:
  int data[maxsize];
  int top;
public:
  SequenceStack() {
    top = -1;
  }

  ~SequenceStack() {

  }

  void push(int x) {
    if (isFull()) {
      cout << "stack is full" << endl;
      return;
    }
    data[++top] = x;
  }

  int pop() {
    if (isEmpty()) {
      cout << "stack is empty" << endl;
      return -1;
    }
    return data[top--];
  }

  int getTop() {
    if (isEmpty()) {
      cout << "stack is empty" << endl;
      return -1;
    }
    return data[top];
  }

  bool isEmpty() {return top==-1;}
  bool isFull() {return top==maxsize-1;}
};

int main() {
  SequenceStack st = SequenceStack();
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  for (int i=0; i<n; ++i) st.push(a[i]);
  while (!st.isEmpty()) {
    cout << st.getTop() << endl;
    st.pop();
  }
  cout << endl;
  return 0;
}