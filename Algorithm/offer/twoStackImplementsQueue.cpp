#include <bits/stdc++.h>
using namespace std;


class Queue {
private:
  stack<int> data, aux;
  // front 存放数据的栈先转换到辅助栈中，刚好讲数据栈的数据逆置 成为一个队列  获取对头元素，即为获取辅助栈
  // 栈顶元素
  
  // pop 对辅助栈pop 即为对队列进行pop

  // empty 判断数据栈是否为空

public:
  void push(int x) {data.push(x);}

  int front() {
    if (isEmpty()) {
      cout << "queue is null" << endl;
      return -1;
    }
    reverse(data, aux);
    int res = aux.top();
    reverse(aux, data);
    return res;
  }

  void pop() {
    if (isEmpty()) {
      cout << "queue is null, can't pop" << endl;
      return;
    }
    reverse(data, aux);
    aux.pop();
    reverse(aux, data);
  }
  bool isEmpty() {
    return data.empty();
  }


  void reverse(stack<int> &a, stack<int> &b) {
    while (!a.empty()) {
      b.push(a.top());a.pop();
    }
  }

};

int main() {
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  Queue q;
  for (int i=0; i<n; ++i) q.push(a[i]);
  while (!q.isEmpty()) {
    cout << q.front() << " ";q.pop();
  }
  cout << endl;
  return 0;
}