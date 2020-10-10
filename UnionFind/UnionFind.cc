#include <bits/stdc++.h>
#include <iostream>
using namespace std;

namespace UF1{
  class UnionFind {
  private:
    int *father;
    int count;
  public:
    UnionFind(int n) {
      count = n;
      father = new int[n];
      for (int i=0; i<n; ++i) father[i] = i;
    }


    ~UnionFind() {
      delete[] father;
    }

    int find(int x) {
      assert(x >= 0 && x < count);
      while (x != father[x]) {
        x = father[x];
      }
      return x;
    }

    void Union(int x, int y) {
      int fx = find(x);
      int fy = find(y);
      if (fx != fy) {
        father[fx] = fy;
      }
    }

    bool isConnected(int x, int y) {
      return find(x) == find(y);
    }
  };
}


namespace UF2{
  class UnionFind {
  private:
    int *father;
    int count;
  public:
    UnionFind(int n) {
      count = n;
      father = new int[n+1];
      for (int i=1; i<=n; ++i) father[i] = i;
    }


    ~UnionFind() {
      delete[] father;
    }

    // O(n)
    // int find(int x) {
    //   assert(x >= 0 && x < count);
    //   while (x != father[x]) {
    //     x = father[x];
    //   }
    //   return x;
    // }
    

    // O(n) -> O(1)
    int find(int x) {
      int a = x;
      while (x != father[x]) x = father[x];
      while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
      }

      return x;
    }



    // 如何优化  路径压缩

    void Union(int x, int y) {
      int fx = find(x);
      int fy = find(y);
      if (fx != fy) {
        father[fx] = fy;
      }
    }

    bool isConnected(int x, int y) {
      return find(x) == find(y);
    }
  };
}
namespace UnionFindTestHelper{
  void testUF1(int n) {
    srand(time(NULL));
    UF1::UnionFind uf = UF1::UnionFind(n);
    time_t startTime = clock();
    for (int i=0; i<n; ++i) {
      int a = rand()%n;
      int b = rand()%n;
      uf.Union(a,b);
    }
    for (int i=0; i<n; ++i) {
      int a = rand()%n;
      int b = rand()%n;
      uf.isConnected(a,b);
    }
  
    time_t endTime = clock();
    cout << "UF1, " << 2*n << " ops, " << double(endTime - startTime)/CLOCKS_PER_SEC << "s" << endl;
  }

  void testUF2(int n) {
    srand(time(NULL));
    UF2::UnionFind uf = UF2::UnionFind(n);
    time_t startTime = clock();
    for (int i=0; i<n; ++i) {
      int a = rand()%n;
      int b = rand()%n;
      uf.Union(a,b);
    }
    for (int i=0; i<n; ++i) {
      int a = rand()%n;
      int b = rand()%n;
      uf.isConnected(a,b);
    }
  
    time_t endTime = clock();
    cout << "UF2, " << 2*n << " ops, " << double(endTime - startTime)/CLOCKS_PER_SEC << "s" << endl;
  }
} 

const int N=1010;
bool isRoot[N];
int main() {
  freopen("in.txt", "r", stdin);
  int n,m,a,b;
  cin >> n >> m;

  UF2::UnionFind uf(n);
  while (m --) {
    cin >> a >> b;
    uf.Union(a,b);
  }
  int res = 0;
  for (int i=1; i<=n; ++i) {
    isRoot[uf.find(i)] = 1;
  }
  for (int i=1; i<=n; ++i) {
    res += isRoot[i];
  }
  cout << res << endl;
  return 0;
}


// int main() {
//   int n = 100000;
//   UnionFindTestHelper::testUF1(n);
//   UnionFindTestHelper::testUF2(n);
//   return 0;
// }