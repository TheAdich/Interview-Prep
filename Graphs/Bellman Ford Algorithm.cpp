/*
By Ali Hasan

Watch (Abdul Bari) for concept : https://www.youtube.com/watch?v=FtN3BYH2Zes&t=90s

CONTENT
CONTENT
#Generic graph
#Printing weighted graph
#Bellman Ford Algorithm
*/

#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph{

	map<T,list<pair<T,int>>> adjList;

public:

	void addEdge(T u, T v, int weight, bool bidir=true)
	{
		pair<T,int> p;
		p = make_pair(v,weight);

		adjList[u].push_back(p);
		if(bidir==true)
			{	
				p = make_pair(u,weight);
				adjList[v].push_back(p);
			}
	}

	void printAdjList()
	{
		for(auto i : adjList)
		{
			cout<<i.first<<"->";
			for(auto vertex : i.second)
				{
					cout<<"("<<vertex.first<<","<<vertex.second<<")";
				}
			cout<<endl;
		}
	}

	void bellmanForgAlgo(T src)
	{

		//MAKE EDGELIST
		list<pair<T,pair<T,int>>> edgeList;

		for(auto i : adjList)
		{
			auto node = i.first;
			for(auto j : adjList[node])
			{
				edgeList.push_back(make_pair(node,make_pair(j.first,j.second)));
			}
		}
		cout<<endl<<"Edge List"<<endl;
		for(auto i : edgeList)
		{
			cout<<"("<<i.first<<","<<i.second.first<<")"<<" Weight :"<<i.second.second<<endl;
		}

		map<T,int> dist;
		//INITIALISING
		int vertex = 1;
		for(auto i : adjList)
		{
			dist[i.first] = INT_MAX;
			++vertex;
		}
		dist[src] = 0;

		cout<<endl<<"No. of Vertex = "<<vertex;
		for(int i = 0 ; i < vertex ; i++)
		{
			//RELAX AT EACH STEP
			for(auto j : edgeList)
			{
				T u = j.first;
				T v = j.second.first;
				T weight = j.second.second;
				if(dist[v] > dist[u] + weight)
				{
					dist[v] = dist[u] + weight;
				}

			}
		}

		//PRINT FINAL DISTANCES
		cout<<endl<<"Shortest distance by Bellman Ford Algo"<<endl;

		for(auto i : dist)
		{
			cout<<"Distance of "<<i.first<<" from "<<src<<" = "<<i.second<<endl;
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

  g.addEdge(1,2,6,false);
  g.addEdge(1,3,5,false);
  g.addEdge(1,4,5,false);
  g.addEdge(2,5,-1,false);
  g.addEdge(3,2,-2,false);
  g.addEdge(4,3,-2,false);
  g.addEdge(3,5,1,false);
  g.addEdge(4,6,-1,false);
  g.addEdge(6,7,3,false);
  g.addEdge(5,7,3,false);
  g.addEdge(7,7,0,false);

  g.printAdjList();
  g.bellmanForgAlgo(1);


}