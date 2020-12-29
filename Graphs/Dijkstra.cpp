/*
By Ali Hasan
You can find Prateek bhaiya's code here https://ide.codingblocks.com/s/3059
Best concept explanation (Abdul Bari) : https://www.youtube.com/watch?v=XB4MIexjvY0&t=479s
Implementation explanation ( Coding Blocks ) : https://www.youtube.com/watch?v=NR4fpjuxnPA

I know mine is kinds same (map X unordred_map) cause I saw his explanation then implemented and no way I was going to make the whole input

CONTENTS
#Generic graph
#Printing weighted graph
#Dijksta for single source shortest path algorithm

Have Fun
*/

#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Graph {

	unordered_map<T, list<pair<T, int>>> adjList;

public:
	Graph() {}

	void addEdge(T u, T v, int weight, bool bidir = false)
	{
		pair<T, int> p;
		p = make_pair(v, weight);

		adjList[u].push_back(p);
		if (bidir == true)
		{
			p = make_pair(u, weight);
			adjList[v].push_back(p);
		}
	}

	void printAdjList()
	{
		for (auto i : adjList)
		{
			cout << i.first << "->";
			for (auto vertex : i.second)
			{
				cout << "(" << vertex.first << "," << vertex.second << ")";
			}
			cout << endl;
		}
	}

	void dijkstraSSSP(T src)
	{
		unordered_map<T, int> dist;

		for (auto i : adjList)
			dist[i.first] = INT_MAX;

		dist[src] = 0;

		set<pair<int, T>> set;
		set.insert(make_pair(dist[src], src));

		while (!set.empty())
		{
			//By deafult SET is SORTED
			auto p = *(set.begin());
			T node = p.second;
			// int nodeDist = p.first;

			set.erase(set.begin());

			for (auto i : adjList[node])
			{
				auto child = i.first;
				auto childDist = i.second;

				if (dist[child] > dist[node] + childDist)
				{
					auto ptr = set.find(make_pair(dist[child], child));
					if (ptr != set.end())
					{
						set.erase(ptr);
					}
					dist[child] = dist[node] + childDist;
					set.insert(make_pair(dist[child], child));
				}
			}

		}

		for (auto i : dist)
		{
			if (i.first == src)
				continue;
			if (i.second == INT_MAX)
			{
				cout << -1 << " ";
			}
			else cout << src << " to " << i.first << " -> " << i.second << "\n";
		}

	}


};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif
	// Graph<string> india;
	// india.addEdge("Amritsar","Delhi",1);
	// india.addEdge("Amritsar","Jaipur",4);
	// india.addEdge("Jaipur","Delhi",2);
	// india.addEdge("Jaipur","Mumbai",8);
	// india.addEdge("Bhopal","Agra",2);
	// india.addEdge("Mumbai","Bhopal",3);
	// india.addEdge("Agra","Delhi",1);

	// india.printAdjList();
	// india.dijkstraSSSP("Amritsar");

	Graph<char> g;

	g.addEdge('A', 'B', 50);
	g.addEdge('A', 'C', 3);
	g.addEdge('A', 'D', 70);
	g.addEdge('A', 'E', 9);
	g.addEdge('A', 'F', 10);

	g.addEdge('B', 'C', 3);
	g.addEdge('B', 'D', 6);
	g.addEdge('B', 'E', 3);
	g.addEdge('B', 'F', 2);

	g.addEdge('C', 'B', 2);
	g.addEdge('C', 'D', 10);
	g.addEdge('C', 'E', 6);
	g.addEdge('C', 'F', 6);

	g.addEdge('D', 'E', 6);
	g.addEdge('D', 'F', 5);

	g.addEdge('E', 'D', 2);
	g.addEdge('E', 'F', 4);

	g.addEdge('F', 'F', 0);


	g.printAdjList();
	cout << endl;
	g.dijkstraSSSP('A');

	// int t;
	// cin>>t;

	// while(t!=0)
	// {
	// 	Graph<int> g;

	// 	int node,edge;
	// 	cin>>node>>edge;

	// 	for(int i = 0 ; i < node ; i++)
	// 	{
	// 		int a,b;
	// 		cin>>a>>b;
	// 		int weight;
	// 		cin>>weight;

	// 		g.addEdge(a,b,weight);
	// 	}

	// 	int src;
	// 	cin>>src;

	// 	g.dijkstraSSSP(src);

	// 	--t;

	// }


}
