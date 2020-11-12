/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-19 04:13:20
 */
#ifndef __EDGE_H__
#define __EDGE_H__

template <typename Weight>
class Edge {
private:
  int a, b;
  Weight weight;
public:
  Edge(int a, int b, Weight weight) {
    this->a = a;
    this->b = b;
    this->weight = weight;
  }

  Edge() {}
  ~Edge() {}

  int v() {return a;}
  int w() {return b;}

  int other(int x) {
    assert(x==a || x==b);
    return x==a?a:b;  
  }

  friend  ostream& operator<<(ostream& os, const Edge& e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }


    bool operator<(Edge<Weight>& e){
        return weight<e.wt();
    }

    bool operator<=(Edge<Weight>& e){
        return weight<=e.wt();
    }

    bool operator>=(Edge<Weight>& e){
        return weight>=e.wt();
    }

    bool operator>(Edge<Weight>& e){
        return weight>e.wt();
    }

    bool operator==(Edge<Weight>& e){
        return weight==e.wt();
    }
};



#endif // __EDGE_H__