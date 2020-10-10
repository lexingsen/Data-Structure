#include <bits/stdc++.h>
using namespace std;




void move(char a, char c) {
  cout << a << "->" << c << endl;
}

void hanoi(int n, char a, char b, char c) {
  if (n == 1) {
    move(a,c);
  } else {
    hanoi(n-1, a,c,b);
    move(a,c);
    hanoi(n-1, b,a,c);
  }
}





int main() {
  hanoi(4,'a','b','c');
  return 0;
}