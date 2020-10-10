#include <bits/stdc++.h>
using namespace std;

const int maxsize=0;
class SharedStack {
public:
  int leftTop;
  int rightTop;

  int data[maxsize];
private:  
  SharedStack() {}
  ~SharedStack() {}

  bool isEmpty() {return leftTop==-1 && rightTop==maxsize;}
  bool isFull() {return leftTop+1==rightTop;}
  bool isLeftEmpty() {return leftTop==-1;}
  bool isRightEmpty() {return rightTop==maxsize;}
  int getLeftTop() {
    if (isLeftEmpty()) {
      cout << "left stack is empty" << endl;
      return -1;
    }
    return data[leftTop--];
  }
  int getRightTop() {
    if (isRightEmpty()) {
      cout << "right stack is empty" << endl;
      return -1;
    }
    return data[leftTop++];
  }

  void pushLeft(int x) {
    if (isFull()) {
      cout << "stack is full" << endl;
      return;
    }
    data[++ leftTop] = x;
  }
  void pushRight(int x) {
    if (isFull()) {
      cout << "stack is full" << endl;
      return;
    }
    data[-- rightTop] = x;
  }
  void popLeft() {
    if (isLeftEmpty()) {
      cout << "left stack is empty" << endl;
      return;
    }
    data[leftTop --];
  }
  void popRight() {
    if (isLeftEmpty()) {
      cout << "right stack is empty" << endl;
      return;
    }
    data[rightTop ++];
  }
};

int main() {
  return 0;
}

// shell