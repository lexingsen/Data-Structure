#include <bits/stdc++.h>
using namespace std;

// knuth morris pratt

#define N 100
int Next[N];

void getNext(char s[], int n) {
  int j = -1;
  Next[0] = -1;
  for (int i=1; i<n; ++i) {
    while (j != -1 && s[i]!=s[j+1]) j = Next[j];
    if (s[i] == s[j+1]) {
      j ++;
    }
    Next[i] = j;
  }
}

int cnt = 0;
bool kmp(char text[], char pattern[]) {
  int n = strlen(text), m = strlen(pattern);
  getNext(pattern, m);
  int j = -1;
  for (int i=0; i<n; ++i) {
    while (j!=-1 && text[i]!=pattern[j+1]) {
      j = Next[j];
      cout << "j = " << j << endl;
      cnt ++;
    }
    if (text[i] == pattern[j+1]) {
      j ++;
    }
    if (j==m-1) return true;
  }
  return false;
}

int eKmp(char text[], char pattern[]) {
  int res = 0;
  int n = strlen(text), m = strlen(pattern);
  getNext(pattern, m);
  int j = -1;
  for (int i=0; i<n; ++i) {
    while (j!=-1 && text[i]!=pattern[j+1]) j = Next[j];
    if (text[i] == pattern[j+1]) {
      j ++;
    }
    if (j==m-1) {
      res ++;
      j = Next[j];
    }
  }
  return res;
}

int main() {
  char a[] = "aaaaaaaab";
  char b[] = "aaaab";
  cout << kmp(a, b) << endl;
  cout << "cnt = " << cnt << endl;
  getNext(b, strlen(b));
  for (int i=0; i<strlen(b); ++i) {
    cout << Next[i];
  }
  cout << endl;
  return 0;
}