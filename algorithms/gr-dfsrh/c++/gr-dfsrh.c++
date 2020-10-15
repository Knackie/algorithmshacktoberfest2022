/*
  The below algorithm is based on the DFS travesal of a graph
  Time complexity of the algorithm is 0(E + V) where E is the number of edges and V is the number of vertices
  Space Complexity is 0(V) as we will be using stack for keeping track of vertices visited.
*/

#include <bits/stdc++.h>
using namespace std;

// we will be representing graph in the form of adjacency list
class Graph {
  int vertices; // number of vertices
  list<int> *adj; // pointer to an array containing adjacency list

  public:
    Graph(int v) {
      // contructor and giving number of vertices
      this->vertices = v;
      this->adj = new list<int>[v];
    }

    void addEdge(int start, int end) {
      // params describing edge between start to end
      adj[start].push_back(end);
    }

    void dfsHelperFunction(int vertex, bool visited[]) {

      // mark the visited node as true
      visited[vertex] = true;
      cout << vertex << " ";

      list<int>::iterator i;
      // iterating to every node pointed by the vertext in the adjacency list
      for (i = adj[vertex].begin(); i != adj[vertex].end(); i++) {
        if (!visited[*i]) {
          dfsHelperFunction(*i, visited);
        }
      }
    }

    void dfs() { // dfs algorithm starts here
      
      // creating a visited array 
      bool *visited = new bool[vertices];
      for (int i = 0; i < vertices; i++) {
        visited[i] = false; // initilalizing every vertice visited to be false
      }

      for (int i = 0; i < vertices; i++) {
        if (visited[i] == false) {
          dfsHelperFunction(i, visited);
        }
      }
    }
}

int main() {
  Graph g(4);
  g.addEdge(0, 1); 
  g.addEdge(0, 2); 
  g.addEdge(1, 2); 
  g.addEdge(2, 0); 
  g.addEdge(2, 3); 
  g.addEdge(3, 3); 

  cout << "Following is Depth First Traversal\n"; 
  g.dfs();
}