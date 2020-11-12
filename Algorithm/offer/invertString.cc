/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-25 10:14:37
 */
#include <bits/stdc++.h>
using namespace std;



class TimeGuard {
public:
  std::string name;
  std::chrono::high_resolution_clock::time_point start;

  TimeGuard(std::string name) {
    this->name = name;
    start = std::chrono::high_resolution_clock::now();
  }


  ~TimeGuard() {
    std::cout << name << " cost time : " << std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now() - start).count() << "ms" << endl;
    
  }
};


void invertString(char *s) {
  stack<char> st;
  for (int i=0; i<strlen(s); ++i) {
    st.push(s[i]);
  }

  int i = 0;
  while (!st.empty()) {
    s[i ++] = st.top();st.pop();
  }
}




int main() {
  char a[] = "helloworld";
  cout << a << endl;
  {
    TimeGuard("insert string");
    invertString(a);
  }
  cout << a << endl;
  return 0;
}