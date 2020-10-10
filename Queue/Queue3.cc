#include <bits/stdc++.h>
using namespace std;


const int N=10;

// 标志法 tag=0 队空  tag=1 队列满
class CircleQueue {
private: 
  int data[N];
  int front, rear;
  bool tag;
public:
  CircleQueue() {
    memset(data, 0, sizeof(data));
    rear = front = 0;
    tag=0;
  }

  ~CircleQueue() {

  }

  int length() {
    return tag==1?N:(rear-front+N)%N;
  }

  void enQueue(int x) {
    if (isFull()) {
      cout << "queue is full" << endl;
      return;
    }
    data[rear] = x;
    rear = (rear+1)%N;
    if (rear == front && !tag) tag=1;
  }

  int deQueue() {
    if (isEmpty()) {
      cout << "queue is null" << endl;
      return -1;
    }
    int x = data[front];
    front = (front+1)%N;
    return x;
  }

  int getFront() {
    if (isEmpty()) {
      cout << "queue is empty" << endl;
      return -1;
    }
    return data[front];
  }


  bool isEmpty() {
    return length() == 0;
  }

  bool isFull() {
    return length() == N;
  }
};

int main() {
  int a[] = {1,2,3,4,5};
  int n = sizeof(a)/sizeof(int);
  CircleQueue q;
  for (int i=0; i<n; ++i) q.enQueue(a[i]);
  while (!q.isEmpty()) {
    cout << q.getFront() << " ";
    q.deQueue();
  }
  cout << endl;
  return 0;  
}