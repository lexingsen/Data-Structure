#include <bits/stdc++.h>
using namespace std;

class Stack {
private: 
  queue<int> data, aux;

  // aux用来保存在data队列中除了最后一个元素外的其他所有元素
public:
  void push(int x) {data.push(x);}
  
  void pop() {
    while (data.size() > 1) {
      aux.push(data.front());data.pop();
    }
    data.pop();
    while (!aux.empty()) {
      data.push(aux.front());aux.pop();
    }
  }
  
  int top() {
    while (data.size() > 1) {
      aux.push(data.front());data.pop();
    }
    int res = data.front();
    aux.push(data.front());data.pop();
    while (!aux.empty()) {
      data.push(aux.front());aux.pop();
    }
    return res;
  }

  bool isEmpty() {return data.empty();}
};


int main() {
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  Stack s;
  for (int i=0; i<n; ++i) s.push(a[i]);
  while (!s.isEmpty()) {
    cout << s.top() << " ";s.pop();
  }
  cout << endl;
  return 0;
}