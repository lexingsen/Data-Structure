import java.util.ArrayList;
import java.util.Stack;

/*
 * @Description:  
 * @Language: 
 * @Author: 
 * @Date: 2020-11-09 22:35:57
 */

class Graph {
  private int vertexSize;
  private int[][] map;
  private ArrayList<String> vertex;
  private boolean[] isVisited;

  public Graph(int vertexSize) {
    this.vertexSize = vertexSize;
    map = new int[vertexSize][vertexSize];
    vertex = new ArrayList<String>();
    isVisited = new boolean[vertexSize];
  }

  public void addVertex(String v) {
    vertex.add(v);
  }

  public void addEdge(int a, int b, int w) {
    map[a][b] = map[b][a] = w;
  }


  public void dfs() {
    for (int i=0; i<vertexSize; ++i) {
      isVisited[i] = false;
    }

    Stack<Integer> stack = new Stack<>();
    stack.push(0);
    int i = 0;
    System.out.print(vertex.get(0)+"-");
    boolean flag = false;
    while (!stack.empty()) {
      int k = stack.peek();
      isVisited[k] = true;
      flag = false;
      i=0;
      for (;i<vertexSize; ++i) {
        if (!isVisited[i] && map[k][i] == 1) {
          stack.push(i);
          System.out.print(vertex.get(i)+"-");
          flag = true;
        }
      }
      if (!flag) {
        stack.pop();
      }
    }
    
  }
  public static void main(String[] args) {
    String[] vertex = {"A", "B", "C", "D"};
    Graph graph = new Graph(vertex.length);
    for (String string:vertex) {
      graph.addVertex(string);
      graph.addEdge(0,2,1);
      graph.addEdge(0,3,1);
      graph.addEdge(1,3,1);
    }

    graph.dfs();
  }
}