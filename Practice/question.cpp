#include<bits/stdc++.h>
#include<list>
#include<queue>

using namespace std;

template <typename T>
class Graph{

  map<T,list<T>> adjList;

public:
  Graph(){

  }

  void addEdge(T u, T v,bool bidir = true){

    adjList[u].push_back(v);
    if(bidir){
      adjList[v].push_back(u);
    }
  }

  void print()
  {
    for(auto i: adjList){
      cout<<i.first<<"=>";

      for(auto j: i.second){
        cout<<j<<",";
      }
      cout<<endl;
    }
  }

  void printBFS(T src)
  {
    queue<T> q;

    map<T,bool> visited;

    visited[src] = true;

    q.push(src);

    while(!q.empty())
    {
      T top = q.front();
      cout<<top<<" ";
      q.pop();

      for(auto i : adjList[top])
        {
          if(!visited[i])
          {
            q.push(i);
            visited[i] = true;
          }
        }
    }
  }

  void BFS_SSSP(T src)
  {
    queue<T> q;

    map<T,bool> visited;
    map<T,int> dist;


    visited[src] = true;
    dist[src] = 0;

    q.push(src);

    while(!q.empty())
    {
      T top = q.front();
      cout<<top<<" is at a distance of "<<dist[top];
      q.pop();

      for(auto i : adjList[top])
        {
          if(!visited[i])
          {
            q.push(i);
            visited[i] = true;
            dist[i] = dist[top] + 1;
          }
        }
        cout<<endl;
    }
  }

  void _DFS(T node, map<T, bool> &visited)
  {
    visited[node] = true;
    cout<<node<<" ";

    for(auto i : adjList[node])
    {
      if(!visited[i])
        _DFS(i,visited);
    }
  }

  void DFS(T src)
  {
    map<T,bool> visited;
    _DFS(src,visited);
  }

  void _TS(T node, map<T, bool> &visited, stack<T> &stack)
  {
    visited[node] = true;

    for(auto neighbour : adjList[node])
    {
      if(!visited[neighbour])
        _TS(neighbour,visited,stack);
    }

    stack.push(node);
  }

  void TS()
  {
    stack<T> stack;
    map<T, bool> visited;

    for(auto i : adjList)
    {
      T node = i.first;
      if(!visited[node])
        _TS(node, visited, stack);
    }

    while(!stack.empty())
    {
      cout<<stack.top()<<" ";
      stack.pop();
    }
  }

  void _DFS_DetectCycle(T node, map<T, bool> &visited)

  void DFS_DetectCycle()
  {
    map<T, bool> visited;
    map<T, bool> stack;

    for(auto i : adjList)
    {

    }
  }

  /*
  We say that a graph has a cycle if there is an edge between 
  U and V such that 
  If V is adjacent to U and V is already visited and V is also in
  queue which means that V also is left to travers
  and vice-e-versa for V and U

  In simple words if we say that U meets a person that is 
  already visited but that person also still left to traverse then 
  there is a cycle

  In more simple words it's like there are two people who are
  trying to find maybe love. If a person A finds person B who is 
  also looking for love then there is a cycle.

  But it may happen that person A is tring to find love but 
  person B with whom he/she wants to create a cycle is not 
  adjacent.
  */
  int cyclicBFS(T src)
  {
    map<T, bool> visited;
    map<T, bool> inQueue;

    queue<T> q;
    q.push(src);
    visited[src] = true;
    inQueue[src] = true;

    while(!q.empty())
    {
      
    }
  }

};

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);

  freopen("output.txt","w",stdout);
  #endif

  Graph<int> g;

  // int n;
  // cin>>n;

  g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

  // for(int i = 0 ; i < n ; i++)
  // {
  //   int x,y;
  //   cin>>x>>y;
  //   g.addEdge(x,y,false);
  // }

  g.print();
  cout<<endl;
  // g.dfsDirectedCycleDetection();
  
}