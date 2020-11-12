#ifndef __SPARSEGRAPH_H__
#define __SPARSEGRAPH_H__


#include <bits/stdc++.h>
using namespace std;

template <typename Weight>
class SparseGraph{

private:
    int n, m;       // 节点数和边数
    bool directed;  // 是否为有向图
    vector<vector<Edge<Weight>* >> g;  // 图的具体数据

public:
    // 构造函数
    SparseGraph( int n , bool directed ){
        assert( n >= 0 );
        this->n = n;
        this->m = 0;    // 初始化没有任何边
        this->directed = directed;
        // g初始化为n个空的vector, 表示每一个g[i]都为空, 即没有任和边
        g = vector<vector<Edge<Weight>* >>(n, vector<Edge<Weight>* >());
    }

    ~SparseGraph(){
        for(int i=0; i<n; ++i){
            for(int j=0; j<g[i].size(); ++j)
                delete g[i][j];
        }
    }

    int V(){ return n;} // 返回节点个数
    int E(){ return m;} // 返回边的个数

    // 向图中添加一个边
    void addEdge( int v, int w, Weight weight){

        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        g[v].push_back(new Edge<Weight>(v, w, weight));
        if( v != w && !directed )
            g[w].push_back(new Edge<Weight>(w, v, weight));

        m ++;
    }

    // 验证图中是否有从v到w的边
    bool hasEdge( int v , int w ){

        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        for( int i = 0 ; i < g[v].size() ; i ++ )
            if( g[v][i]->other(v) == w )
                return true;
        return false;
    }

    // 显示图的信息
    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < g[i].size() ; j ++ )
                cout<<"( to:"<<g[i][j]->w()<<", wt:"<<g[i][j]->wt()<<")\t";
            cout<<endl;
        }
    }

    // 邻边迭代器, 传入一个图和一个顶点,
    // 迭代在这个图中和这个顶点向连的所有顶点
    class adjIterator{
    private:
        SparseGraph &G; // 图G的引用
        int v;
        int index;

    public:
        // 构造函数
        adjIterator(SparseGraph &graph, int v): G(graph){
            this->v = v;
            this->index = 0;
        }

        ~adjIterator(){}

        // 返回图G中与顶点v相连接的第一个顶点
        Edge<Weight>* begin(){
            index = 0;
            if( G.g[v].size() )
                return G.g[v][index];
            // 若没有顶点和v相连接, 则返回-1
            return NULL;
        }

        // 返回图G中与顶点v相连接的下一个顶点
        Edge<Weight>* next(){
            index ++;
            if( index < G.g[v].size() )
                return G.g[v][index];
            // 若没有顶点和v相连接, 则返回-1
            return NULL;
        }

        // 查看是否已经迭代完了图G中与顶点v相连接的所有顶点
        bool end(){
            return index >= G.g[v].size();
        }
    };
};
#endif // __SPARSEGRAPH_H__