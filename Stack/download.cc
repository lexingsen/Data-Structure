#include <bits/stdc++.h>
#include <thread>
using namespace std;


int main() {
  cout << "helloworld" << endl;
  thread t1([](){cout << "hello" << endl;});
  thread t2([](){cout << "world" << endl;});
  t1.join();
  t2.join();
  return 0;
}