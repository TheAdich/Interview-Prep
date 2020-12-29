/*
By Ali Hasan

CONTENTS
#Generic graph
#Printing weighted graph
#Taking Transpose of Graph
#Kosaraju's DFS Algorithm (DAMN EASY)

Have Fun 
*/
#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph{

	map<T,vector<T>> adjList;

public:
	Graph()
	{
		
	}

	void addEdge(T u, T v, bool bidir=true)
	{
		adjList[u].push_back(v);
		if(bidir==true)
			adjList[v].push_back(u);
	}

	void printAdjList()
	{
		for(auto i : adjList)
		{
			cout<<i.first<<"->";
			for(auto vertex : i.second)
				cout<<vertex<<",";
			cout<<endl;
		}
	}

	void graphTranspose(map<T,vector<T>> adjList1, map<T,vector<T>>& adjList2)
	{
		for(auto i : adjList1)
		{
			for(auto vertex : i.second)
				{
					T u = i.first;
					T v = vertex;

					adjList2[v].push_back(u);
				}
		}

		cout<<endl<<"Transpose of Graph"<<endl;

		for(auto i : adjList2)
		{
			cout<<i.first<<"->";
			for(auto j : i.second)
				cout<<j<<",";
			cout<<endl;
		}
	}

	int kosarajuAlgoHelper(T src, map<T,vector<T>>& adjListHelp, map<T,bool> &visited, int &counter)
	{
		visited[src] = true;
		for(T i:adjListHelp[src])
		{
			if(!visited[i])
			{
				visited[i] = true;
				++counter;
				kosarajuAlgoHelper(i,adjListHelp,visited,counter);
			}
		}
		return counter;
	}

	bool kosarajuAlgo(int vertex)
	{
		/*
		STEP 1: Select any Node
		STEP 2: Call DFS from that Node
		STEP 3: If you can reach all other nodes from Node -> Awesome
				else not Strongly Connected
		*/
		map<T,bool> visited;
		T src = adjList.begin()->first;
		int counter = 0;
		kosarajuAlgoHelper(src,adjList,visited,counter);
		cout<<endl<<"Counter 1: "<<counter<<endl;
		if(counter!=vertex-1)
			return false;

		/*
		STEP 1: You are here that means you covered all nodes from your selected Node
				Good Choice
		STEP 2: Take Transpose of graph i.e. simple reverse the path
		*/
		//TRANSPOSE
		map<T,vector<T>> adjList2;
		graphTranspose(adjList,adjList2);

		/*
		AGAIN
		STEP 1: Select any Node from your Transpose graph
		STEP 2: Call DFS from that Node
		STEP 3: If you can reach all other nodes from Node -> Awesome
				else not Strongly Connected
		*/

		map<T,bool> visited2;
		counter = 0;
		kosarajuAlgoHelper(src,adjList2, visited2,counter);
				cout<<endl<<"Counter 1: "<<counter<<endl;

		if(counter!=vertex-1)
			return false;

		return true;
	}
};


int main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);

  freopen("output.txt","w",stdout);
  #endif

  Graph<int> g;

  /*
  Input for STRONGLY CONNECTED
  Total vertex = 6 
  1,2,3,4,5,6
  */
  // g.addEdge(1,2,false);
  // g.addEdge(2,3,false);
  // g.addEdge(3,4,false);
  // g.addEdge(4,1,false);
  // g.addEdge(4,5,false);
  // g.addEdge(5,6,false);
  // g.addEdge(6,4,false);
	
  /*
  Input for NOT STRONGLY CONNECTED
  Total vertex = 3 
  1,2,3
  */
	
   // g.addEdge(1,2,false);
   // g.addEdge(2,3,false);
   // g.addEdge(1,3,false);

  /*
  Input for STRONGLY CONNECTED
  Total vertex = 6 
  1,2,3,4,5,6
  */
  	g.addEdge(1,2,false);
  	g.addEdge(2,3,false);
  	g.addEdge(3,4,false);
  	g.addEdge(4,2,false);
  	g.addEdge(4,5,false);
  	g.addEdge(5,6,false);
  	g.addEdge(6,1,false);

  cout<<"Original graph"<<endl;
  g.printAdjList();
  if(g.kosarajuAlgo(6))
  	cout<<endl<<"Graph is Strongly Connected"<<endl;
  else
  	cout<<endl<<"Graph is NOT Strongly Connected"<<endl;

	
}