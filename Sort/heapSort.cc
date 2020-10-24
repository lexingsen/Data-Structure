/*
 * @Description: 堆排序
 * @Language: C++
 * @Author: lexinsen
 * @Date: 2020-10-25 00:52:25
 */

/*
不稳定 
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Heap {
private:
  T *data;
  int cnt;
  int capacity;


  void shiftUp(int k) {
    while (k > 1 && data[k/2] < data[k]) {
      swap(data[k], data[k/2]);
      k /= 2;
    }
  }

  void shiftDown(int k) {
    while (2*k <= cnt) {
      int j = 2*k;
      if (j+1<=cnt && data[j+1]<data[j]) j ++;
      if (data[k] <= data[j]) break;
      swap(data[k], data[j]);
      k = j;
    }
  }

  
  

public:
  Heap(int capacity) {
    data = new T[capacity+1];
    this->cnt = 0;
    this->capacity = capacity;
  }
  // heapify
  Heap(T *a, int n) {
    data = new T[n+1];
    for (int i=0; i<n; ++i) data[i+1] = a[i];
    cnt = n;
    for (int i=n/2; i>=1; --i) {
      shiftDown(i);
    }
  }

  ~Heap() {
    delete[] data;
  }

  int size() {
    return cnt;
  }

  // [0,cnt-1]  [1, cnt]
  void insert(T x) {
    assert(cnt+1<=capacity);
    data[cnt + 1] = x;
    cnt ++;
    shiftUp(cnt);
  } 

  T extractMax() {
    assert(cnt > 0);
    T res = data[1];
    swap(data[1], data[cnt]);
    cnt --;
    shiftDown(1);
    return res;
  }



public:
  void show(){
  // 我们的testPrint只能打印100个元素以内的堆的树状信息
    if(size() >= 100){
      cout<<"This print function can only work for less than 100 int";
      return;
    }

    // 我们的testPrint只能处理整数信息
    if(typeid(T) != typeid(int)){
      cout <<"This print function can only work for int item";
      return;
    }

    cout<<"The max heap size is: "<<size()<<endl;
    cout<<"Data in the max heap: ";
    for(int i = 1; i<=size() ;i ++){
      // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
      assert( data[i] >= 0 && data[i] < 100 );
      cout<<data[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    int n = size();
    int max_level = 0;
    int number_per_level = 1;
    while( n > 0 ) {
      max_level += 1;
      n -= number_per_level;
      number_per_level *= 2;
    }

    int max_level_number = int(pow(2, max_level-1));
    int cur_tree_max_level_number = max_level_number;
    int index = 1;
    for( int level = 0 ; level < max_level ; level ++ ){
      string line1 = string(max_level_number*3-1, ' ');

      int cur_level_number = min(cnt-int(pow(2,level))+1,int(pow(2,level)));
      bool isLeft = true;
      for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
        putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
        isLeft = !isLeft;
      }
      cout<<line1<<endl;

      if( level == max_level - 1 )
        break;

      string line2 = string(max_level_number*3-1, ' ');
      for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
        putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
      cout<<line2<<endl;
      cur_tree_max_level_number /= 2;
    }
  }
private:
  void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
    assert(offset + 1 < line.size());
    if( num >= 10 ) {
      line[offset + 0] = '0' + num / 10;
      line[offset + 1] = '0' + num % 10;
    }
    else{
      if(isLeft)
        line[offset + 0] = '0' + num;
      else
        line[offset + 1] = '0' + num;
    }
  }

  void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int sub_sub_tree_width = (sub_tree_width - 1) / 2;
    int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
    assert( offset_left + 1 < line.size() );
    int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
    assert( offset_right < line.size() );
    line[offset_left + 1] = '/';
    line[offset_right + 0] = '\\';
  }
};


void heapSort(int *a, int n) {
  Heap<int> hp(a, n);
  for (int i=n-1; i>=0; --i) a[i] = hp.extractMax();
}


int main() {
  int a[] = {3,5,4,6,1,2};
  int n = sizeof(a)/sizeof(int);
  Heap<int> hp(a,n);
  hp.show();
  return 0;
}