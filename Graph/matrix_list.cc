/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-29 23:50:57
 */


#define MaxVertexNum 100
using VertexType = char;
using EdgeType = int;
class MGraph {
  VertexType Vex[MaxVertexNum];
  EdgeType Edge[MaxVertexNum][MaxVertexNum];
  int vernum, arcnum;
};

class ArcNode {
  int adjvex;
  ArcNode* next;
};

class VNode {
  VertexType data;
  ArcNode *first;
};




void convert(ALgraph &G, int arcs[M]{N}) {
  for (int i=0; i<n; ++i) {
    p = G->v[i].firstarc;
    while (p) {
      arcs[i][p->data]=1;
      p=p->nextarc;
    }    
  }
}