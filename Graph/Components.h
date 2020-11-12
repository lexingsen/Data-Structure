/*
 * @Description: 
 * @Language: 
 * @Author: 
 * @Date: 2020-10-19 04:19:35
 */
#ifndef __COMPONENTS_H__
#define __COMPONENTS_H__
#include <bits/stdc++.h>
using namespace std;

template <typename Graph>
class Component{
private:
    Graph& G;      //图的引用
    bool* visited; //记录dfs过程中节点是否被访问
    int _count;     //连通分量的个数
    int* id;       //每个节点对用的连通分量标记

    void dfs(int v){
        visited[v] = true;
        id[v] = _count;
        typename Graph::adjIterator adj(G, v);
        for(int i=adj.begin(); !adj.end(); i=adj.next()){
            if(!visited[i]){
                dfs(i);
            }
        }
    }

public:
    Component(Graph& graph):G(graph){
        visited = new bool[G.V()];
        id = new int[G.V()];
        _count = 0;
        for(int i=0; i<G.V(); ++i){
            visited[i] = false;
            id[i] = -1;
        }

        for(int i=0; i<G.V(); ++i){
            if(!visited[i]){
                dfs(i);
                _count ++;
            }
        }
    }

    ~Component(){
        delete[] visited;
        delete[] id;
    }

    int count(){
        return _count;
    }

    bool isConnect(int v, int w){
        assert(v>=0 && v<G.V());
        assert(w>=0 && w<G.V());
        return id[v] == id[w];
    }
};
#endif // __COMPONENTS_H__