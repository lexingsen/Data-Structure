#include <bits/stdc++.h>
using namespace std;


int bf(char *text, char *pattern) {
  int i=0,j=0,k=0; //k表示上一次失配的位置
  while (i < strlen(text) && j < strlen(pattern)) {
    if (text[i] == pattern[j]) {
      i ++, j ++;
    } else {
      j = 0;
      i = ++k;
    }
  }  
  if (j >= strlen(pattern)) {
    return k;
  } else {
    return -1;
  }
}

int main() {
  char a[] = {"helloworld"};
  char b[] = {"wor"};
  cout << bf(a, b) << endl;
  return 0;
}